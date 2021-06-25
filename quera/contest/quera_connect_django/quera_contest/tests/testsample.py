from django.db.models import CharField, ForeignKey, PositiveIntegerField, DateTimeField, URLField, Max
from django.shortcuts import get_object_or_404
from django.test import TestCase, Client

from accounts.models import User
from contests.models import Contest
from contests.query import list_problems, list_users, list_submissions, list_problem_submissions, \
    list_user_submissions, list_problem_user_submissions, list_users_solved_problem, user_score, list_final_submissions
from problems.models import Problem, Submission


class TestContest(TestCase):
    fixtures = ["fixtures/sample_data.json", "fixtures/sample_contest.json"]

    def setUp(self):
        self.client = Client()

    def test_sample_problem_model(self):
        problem = Problem.objects.get(pk=1)

        ################## name
        name_label = problem._meta.get_field('name').verbose_name
        self.assertEqual(name_label, 'name')

        type_field = problem._meta.get_field('name')
        self.assertTrue(isinstance(type_field, CharField))

        max_length_argument = problem._meta.get_field('name').max_length
        self.assertEqual(max_length_argument, 50)

        self.assertEqual(problem.name, 'Easy')

        ################## description
        name_label = problem._meta.get_field('description').verbose_name
        self.assertEqual(name_label, 'description')

        type_field = problem._meta.get_field('description')
        self.assertTrue(isinstance(type_field, CharField))

        max_length_argument = problem._meta.get_field('description').max_length
        self.assertEqual(max_length_argument, 1000)

        self.assertEqual(problem.description, 'dish dish')

    def test_sample_submission_model(self):
        submission = Submission.objects.get(pk=1)

        ################## submitted_time
        name_label = submission._meta.get_field('submitted_time').verbose_name
        self.assertEqual(name_label, 'submitted time')

        type_field = submission._meta.get_field('submitted_time')
        self.assertTrue(isinstance(type_field, DateTimeField))

        self.assertEqual(str(submission.submitted_time), "2020-05-16 16:10:00+00:00")

        ################## participant
        name_label = submission._meta.get_field('participant').verbose_name
        self.assertEqual(name_label, 'participant')

        type_field = submission._meta.get_field('participant')
        self.assertTrue(isinstance(type_field, ForeignKey))

        rel_model = submission._meta.get_field('participant').related_model
        self.assertEqual(str(rel_model), "<class 'accounts.models.User'>")

        self.assertEqual(submission.participant.username, 'SAliB')

    def test_list_problem(self):
        qs = list_problems(1)
        self.assertQuerysetEqual(qs, ["<Problem: Problem object (1)>", "<Problem: Problem object (2)>",
                                      "<Problem: Problem object (3)>"], ordered=False)

    def test_sample_list_users(self):
        qs = list_users(1)
        self.assertQuerysetEqual(qs, ["<User: SAliB>", "<User: Saeid>", "<User: Ali>"], ordered=False)

    def test_sample_list_submissions(self):
        qs = list_submissions(1)
        self.assertQuerysetEqual(qs, ["<Submission: Submission object (12)>", "<Submission: Submission object (6)>",
                                      "<Submission: Submission object (16)>", "<Submission: Submission object (5)>",
                                      "<Submission: Submission object (11)>", "<Submission: Submission object (15)>",
                                      "<Submission: Submission object (14)>", "<Submission: Submission object (4)>",
                                      "<Submission: Submission object (10)>", "<Submission: Submission object (9)>",
                                      "<Submission: Submission object (3)>", "<Submission: Submission object (8)>",
                                      "<Submission: Submission object (2)>", "<Submission: Submission object (13)>",
                                      "<Submission: Submission object (1)>", "<Submission: Submission object (7)>"])

    def test_sample_list_problem_submissions(self):
        qs = list_problem_submissions(1, 1)
        self.assertQuerysetEqual(qs, ["<Submission: Submission object (9)>", "<Submission: Submission object (8)>",
                                      "<Submission: Submission object (2)>", "<Submission: Submission object (13)>",
                                      "<Submission: Submission object (1)>", "<Submission: Submission object (7)>"])

    def test_sample_list_user_submissions(self):
        qs = list_user_submissions(1, 1)
        self.assertQuerysetEqual(qs, ["<Submission: Submission object (6)>", "<Submission: Submission object (5)>",
                                      "<Submission: Submission object (4)>", "<Submission: Submission object (3)>",
                                      "<Submission: Submission object (2)>", "<Submission: Submission object (1)>"])

    def test_sample_list_problem_user_submissions(self):
        qs = list_problem_user_submissions(1, 1, 1)
        self.assertQuerysetEqual(qs, ["<Submission: Submission object (2)>", "<Submission: Submission object (1)>"])

    def test_sample_list_users_solved_problem_contest(self):
        qs = list_users_solved_problem(1, 3)
        self.assertQuerysetEqual(qs, ["<User: SAliB>"])

    def test_sample_user_score_contest(self):
        qs = user_score(1, 1)
        self.assertEqual(qs, 600)
        qs = user_score(1, 3)
        self.assertEqual(qs, 540)

    def test_sample_final_submission_contest(self):
        qs = list_final_submissions(1)
        self.assertQuerysetEqual(qs, ["{'participant_id': 1, 'problem_id': 1, 'score__max': 100}",
                                      "{'participant_id': 1, 'problem_id': 2, 'score__max': 200}",
                                      "{'participant_id': 1, 'problem_id': 3, 'score__max': 300}",
                                      "{'participant_id': 2, 'problem_id': 1, 'score__max': 100}",
                                      "{'participant_id': 2, 'problem_id': 2, 'score__max': 120}",
                                      "{'participant_id': 3, 'problem_id': 1, 'score__max': 100}",
                                      "{'participant_id': 3, 'problem_id': 2, 'score__max': 200}",
                                      "{'participant_id': 3, 'problem_id': 3, 'score__max': 240}"])

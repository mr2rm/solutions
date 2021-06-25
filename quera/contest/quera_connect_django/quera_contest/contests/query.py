from django.contrib.auth import get_user_model
from django.db.models import F, Max, Sum

from problems.models import Submission, Problem

User = get_user_model()


def list_problems(contest_id):
    return Problem.objects.filter(contest__id=contest_id)


def list_users(contest_id):
    return User.objects.filter(participants__id=contest_id)


def list_submissions(contest_id):
    return Submission.objects.filter(problem__contest__id=contest_id).order_by('-submitted_time')


def list_problem_submissions(contest_id, problem_id):
    return Submission.objects.filter(problem_id=problem_id, problem__contest__id=contest_id).order_by('-submitted_time')


def list_user_submissions(contest_id, user_id):
    return Submission.objects.filter(
        participant_id=user_id, problem__contest__id=contest_id
    ).order_by('-submitted_time')


def list_problem_user_submissions(contest_id, user_id, problem_id):
    return Submission.objects.filter(problem_id=problem_id, participant_id=user_id,
                                     problem__contest__id=contest_id).order_by('-submitted_time')


def list_users_solved_problem(contest_id, problem_id):
    user_ids = Submission.objects.filter(problem_id=problem_id, problem__contest__id=contest_id,
                                         problem__score=F('score')).order_by('-submitted_time').values_list(
        'participant_id', flat=True)
    return User.objects.filter(id__in=user_ids)


def user_score(contest_id, user_id):
    result = Submission.objects.filter(problem__contest__id=contest_id, participant_id=user_id).values(
        'problem_id').annotate(problem_score=Max('score')).aggregate(total_score=Sum('problem_score'))
    return result['total_score']


def list_final_submissions(contest_id):
    result = Submission.objects.filter(problem__contest__id=contest_id).values('participant_id', 'problem_id').annotate(
        Max('score'))
    return list(result)

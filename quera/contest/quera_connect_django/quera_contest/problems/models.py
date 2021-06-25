from django.db import models

from accounts.models import User


class Problem(models.Model):
    name = models.CharField(max_length=50)
    description = models.CharField(max_length=1000)
    writer = models.ForeignKey(User, on_delete=models.CASCADE)
    score = models.PositiveIntegerField(default=100)


class Submission(models.Model):
    submitted_time = models.DateTimeField(auto_now_add=True)
    participant = models.ForeignKey(User, on_delete=models.CASCADE, related_name='submissions')
    problem = models.ForeignKey(Problem, on_delete=models.CASCADE, related_name='submissions')
    code = models.URLField(max_length=200)
    score = models.PositiveIntegerField(default=0)

from django.db import models
from accounts.models import User
from problems.models import Problem


class Contest(models.Model):
    name = models.CharField(max_length=50)
    holder = models.ForeignKey(User, on_delete=models.CASCADE)
    start_time = models.DateTimeField()
    finish_time = models.DateTimeField()
    is_monetary = models.BooleanField(default=False)
    price = models.PositiveIntegerField(default=0)
    problems = models.ManyToManyField(Problem)
    authors = models.ManyToManyField(User, related_name='authors')
    participants = models.ManyToManyField(User, related_name='participants')

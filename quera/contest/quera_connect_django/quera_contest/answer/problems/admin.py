from django.contrib import admin

from .models import Problem, Submission


@admin.register(Problem)
class ProblemAdmin(admin.ModelAdmin):
    fieldsets = (
        (None, {'fields': ('name', 'score', 'description', 'writer')}),
    )
    list_filter = ('name', 'score', 'writer')
    list_display = ('name', 'score', 'writer')
    list_editable = ('score',)


@admin.register(Submission)
class SubmissionAdmin(admin.ModelAdmin):
    fieldsets = (
        (None, {'fields': ('participant', 'problem', 'code', 'score', 'submitted_time')}),
    )
    list_filter = ('submitted_time', 'participant', 'problem', 'score')
    list_display = ('submitted_time', 'participant', 'problem', 'code', 'score')
    list_editable = ('score',)

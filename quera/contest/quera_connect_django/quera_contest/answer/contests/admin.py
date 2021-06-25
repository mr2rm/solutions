from django.contrib import admin

from .models import Contest


@admin.register(Contest)
class ContestAdmin(admin.ModelAdmin):
    fieldsets = (
        (None, {'fields': ('name', 'is_monetary', 'price', 'start_time', 'finish_time')}),
        ('Holders info', {'fields': (
            'holder', 'authors'
        )}),
        ('Problems info', {'fields': (
            'problems',
        )}),
        ('Participants info', {'fields': (
            'participants',
        )}),
    )
    list_filter = ('start_time', 'finish_time', 'is_monetary')
    list_display = ('name', 'holder', 'start_time', 'finish_time', 'is_monetary', 'price')
    list_editable = ('is_monetary',)

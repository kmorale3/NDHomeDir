from django.contrib import admin

from .models import CandidateProfile
from .models import RecruiterProfile

admin.site.register(CandidateProfile)
admin.site.register(RecruiterProfile)
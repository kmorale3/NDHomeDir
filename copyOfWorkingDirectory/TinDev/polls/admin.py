from django.contrib import admin

from .models import CandidateProfile
from .models import RecruiterProfile
from .models import JobPost

admin.site.register(CandidateProfile)
admin.site.register(RecruiterProfile)
admin.site.register(JobPost)
from django.db import models
from django import forms
from django.contrib.auth.models import User
import datetime

# Create your models here.
class CandidateProfile(models.Model):
    name       = models.CharField(max_length=75)
    profileBio = models.CharField(max_length=500)
    zipcode    = models.CharField(max_length=15)
    skills     = models.CharField(max_length=200)
    githubUser = models.CharField(max_length=15)
    yearsExp   = models.IntegerField()
    education  = models.CharField(max_length=50)
    username   = models.CharField(max_length=15)
    
    @classmethod
    def create(cls,name,profileBio,zipcode,skills,githubUser,yearsExp,education,username):
        candidate = cls(
                        name       = name,
                        profileBio = profileBio,
                        zipcode    = zipcode,
                        skills     = skills,
                        githubUser = githubUser,
                        yearsExp   = yearsExp,
                        education  = education,
                        username   = username
                        )
        return candidate



class RecruiterProfile(models.Model):
    fname       = models.CharField(max_length=75)
    lname       = models.CharField(max_length=75)
    company     = models.CharField(max_length=500)
    zipcode     = models.CharField(max_length=15)
    username    = models.CharField(max_length=15)
    
    @classmethod
    def create(cls,fname,lname,company,zipcode,username):
        recruiter = cls(
                        fname      = fname,
                        lname      = lname,
                        company    = company,
                        zipcode    = zipcode,
                        username   = username
                        )
        return recruiter

class signIn(models.Model):
    signin_username    = forms.CharField(max_length=15)
    signin_password    = forms.CharField(max_length=20)

  

class JobPost(models.Model):
    STATUS = [
    (0,"Inactive"),
    (1,"Active")
    ]
    JOBTYPE = [
    (0,"Full Time"),
    (1,"Part Time")    
    ]
    REMOTE = [
    (0,"In person"),
    (1,"Remote")
    ]
    recruiter        = models.ForeignKey(RecruiterProfile, on_delete=models.CASCADE, related_name='job_posts', default=None)
    interestedCands  = models.ManyToManyField(CandidateProfile, related_name='job_Posts')
    positionTitle    = models.CharField(max_length=75)
    jobType          = models.IntegerField(choices=JOBTYPE)
    cityLocation     = models.CharField(max_length=30)
    stateLocation    = models.CharField(max_length=2) # Must be state abbrev. for locality score computation
    preferredSkills  = models.TextField()
    jobDescription   = models.TextField()
    company          = models.CharField(max_length=75, default = 'a')
    expirationDate   = models.DateField(max_length=30)
    status           = models.IntegerField(choices=STATUS, default=1)
    created_on       = models.DateTimeField(auto_now_add=True)
    numInterestCands = models.IntegerField(default=0)
    compScore        = models.IntegerField(default=-1)

    @classmethod
    def create(cls, recruiter, positionTitle,jobType,cityLocation,stateLocation,preferredSkills,jobDescription,company,expirationDate):
        jobPost = cls(
                        recruiter       = recruiter, 
                        positionTitle   = positionTitle,
                        jobType         = jobType,
                        cityLocation    = cityLocation,
                        stateLocation   = stateLocation,
                        preferredSkills = preferredSkills,
                        jobDescription  = jobDescription,
                        company         = company,
                        expirationDate  = expirationDate,
                        )
        if expirationDate > datetime.now():
            status = 0
   # def get_all_objects():
    #    queryset = JobPost.objects.all()
    #    return queryset


class Favorite(models.Model):
    candidate = models.ForeignKey(CandidateProfile,on_delete=models.CASCADE, related_name='favorites', default=None)
    jobPost   = models.ForeignKey(JobPost,on_delete=models.CASCADE, related_name='favorites',default=None)




from django.db import models
from django import forms
from django.contrib.auth.models import User

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
    positionTitle   = models.CharField(max_length=75)
    jobType         = models.CharField(max_length=75)
    cityLocation    = models.CharField(max_length=30)
    stateLocation   = models.CharField(max_length=30)
    preferredSkills = models.TextField(max_length=50)
    jobDescription  = models.TextField(max_length=1000)
    expirationDate  = models.DateField(max_length=30)
    status          = models.CharField(max_length=10)

    @classmethod
    def create(cls,positionTitle,jobType,cityLocation,stateLocation,preferredSkills,jobDescription,expirationDate,status):
        jobPost = cls(
                        positionTitle   = positionTitle,
                        jobType         = jobType,
                        cityLocation    = cityLocation,
                        stateLocation   = stateLocation,
                        preferredSkills = preferredSkills,
                        jobDescription  = jobDescription,
                        expirationDate  = expirationDate,
                        status          = status
                        )
        return jobPost






from django.shortcuts import render, redirect
from django.contrib import messages, auth
from django.http import HttpResponse
from django.http import HttpResponseRedirect
from django.urls import reverse
from .models import CandidateProfile
from .models import RecruiterProfile
from .models import signIn
from .models import JobPost
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, login
from django.views.generic import ListView, DetailView

def index(request):
	return render(request, 'polls/index.html')

def NewCandidate(request):
    context_object_name = "error_message"
    if 'create_account' in request.GET:
        valid_input = True

        fname      = request.GET['fname']
        lname      = request.GET['lname']
        name       = fname + ' ' + lname
        name       = name[:75]
        bio        = request.GET['bio']
        zipcode    = request.GET['zipcode']
        skills     = request.GET['skills']
        github     = request.GET['github']
        experience = request.GET['experience']
        education  = request.GET['education']
        username   = request.GET['username']
        password1  = request.GET['password1']
        password2  = request.GET['password2']
        if not (fname and lname and zipcode and skills and experience and username and password1 and password2):
            messages.error(request, "Error. Please enter all fields marked with *")
            valid_input = False
        if password1 != password2:
            messages.error(request, "Error. Passwords do not match")
            valid_input = False
        if not experience.isnumeric():
            messages.error(request, "Error. Please enter a number for years of experience")
            valid_input = False
        if not zipcode.isnumeric():
            messages.error(request, "Error. Please enter a valid numerical zipcode")
            valid_input = False
        if not UsernameAvailable(username):
            messages.error(request, "Error. This username is taken")
            valid_input = False
        
        if valid_input:
            candidate = CandidateProfile.create(name,bio,zipcode,skills,github,experience,education,username)
            candidate.save()
            print('New Candidate ID:', candidate.id)
            user = User.objects.create_user(username=username, password=password1)
            user.save()
            return render(request, 'polls/index.html')
    
    return render(request, 'polls/newCandidate.html')

def NewRecruiter(request):
    context_object_name = "error_message"
    if 'create_account' in request.GET:
        valid_input = True

        fname      = request.GET['fname']
        lname      = request.GET['lname']
        zipcode    = request.GET['zipcode']
        company     = request.GET['company']
        username   = request.GET['username']
        password1  = request.GET['password1']
        password2  = request.GET['password2']
        if not (fname and lname and zipcode and company and username and password1 and password2):
            messages.error(request, "Error. Please enter all fields marked with *")
            valid_input = False
        if password1 != password2:
            messages.error(request, "Error. Passwords do not match")
            valid_input = False
        if not zipcode.isnumeric():
            messages.error(request, "Error. Please enter a valid numerical zipcode")
            valid_input = False
        if not UsernameAvailable(username):
            messages.error(request, "Error. This username is taken")
            valid_input = False
        
        if valid_input:
            recruiter = RecruiterProfile.create(fname,lname,company,zipcode,username)
            recruiter.save()
            print('New Recruiter ID:', recruiter.id)
            user = User.objects.create_user(username=username, password=password1)
            user.save()
            return render(request, 'polls/index.html')
    
    return render(request, 'polls/newRecruiter.html')

def UsernameAvailable(proposed_username):
    c_usernames = CandidateProfile.objects.filter(username=proposed_username)
    r_usernames = RecruiterProfile.objects.filter(username=proposed_username)
    if c_usernames or r_usernames:
        return False
    else:
        return True

'''
def SignIn(request):
    # form = models.signIn
    context_object_name = 'signInPage'
    if 'signIn' in request.GET:
        valid_input = True
        username = request.GET['username']
        password = request.GET['password']

        if not (username and password):
            messages.error(request, "Enter a username and password")
            valid_input = False

        user = CandidateProfile.objects.filter(username=username).first()
        if valid_input and not user:
            # don't parse recruiters unless candiates fail
            user = RecruiterProfile.objects.filter(username=username).first()
            if not user:
                messages.error(request, "Unknown username")
                valid_input = False

        if valid_input and not (user.password == password):
            messages.error(request, 'Incorrect password')
            valid_input = False

        if valid_input:
            print('Active User ID:', user.id)
            return render(request, 'polls/signedIn.html', {'username': username})

    return render(request, 'polls/signIn.html')
'''

def SignIn(request):
    context_object_name = 'signInPage'
    if 'signIn' in request.GET:
        valid_input = True
        username = request.GET['username']
        password = request.GET['password']
        if not (username and password):
            messages.error(request, "Enter a username and password")
            valid_input = False

        user = CandidateProfile.objects.filter(username=username).first()
        try:
            account = CandidateProfile.objects.get(username=username)
        except CandidateProfile.DoesNotExist:
            account = None
        homepage = '/polls/candidateHome'
        if valid_input and not user:
            # don't parse recruiters unless candiates fail
            user = RecruiterProfile.objects.filter(username=username).first()
            homepage = '/polls/recruiterHome'
            try:
                account = RecruiterProfile.objects.get(username=username)
            except RecruiterProfile.DoesNotExist:
                account = None
            if not user:
                messages.error(request, "Unknown username")
                valid_input = False

        if valid_input:
            user = authenticate(username=username, password=password)
            print(account.id)
            print(user, "signed in")
            if user:
                auth.login(request, user)
                request.session['username'] = account.id
                print('Session:', request.session['username'])
                return redirect(homepage)  # 4
            else:
                messages.error(request, "Invalid password")
    return render(request, 'polls/signIn.html')

def recruiterHome(request):
    context_object_name = 'recruiterHomePage'
    print(request.session['username'])
    user = RecruiterProfile.objects.get(pk=request.session['username'])
    print(user.fname)
    context = {
        'user': user
    }
    if 'signOut' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request)
        print('Signed out')
        return redirect('/polls')
    return render(request, 'polls/recruiterHome.html',context=context)

def candidateHome(request):
    context_object_name = 'candidateHomePage'
    print(request.session['username'])
    user = CandidateProfile.objects.get(pk=request.session['username'])
    print(user.name)
    context = {
        'user': user
    }
    if 'signOut' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request)
        print('Signed out')
        return redirect('/polls')
    return render(request, 'polls/candidateHome.html',context=context)


def SignedIn(request):
    context_object_name = 'signedInPage'
    print(request.GET['username'])
    return render(request, 'polls/signedIn.html')

def signOut(request, user):
    if 'signOut' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request,user)
        print('Signed out')
        return redirect('/polls/index.html')

def NewJobPost(request):
    context_object_name = "newJobPost"
    if 'create_post' in request.GET:
        valid_input = True

        positionTitle   = request.GET['positionTitle']
        jobType         = request.GET['jobType']
        cityLocation    = request.GET['cityLocation']
        stateLocation   = request.GET['stateLocation']
        preferredSkills = request.GET['preferredSkills']
        jobDescription  = request.GET['jobDescription']
        expirationDate  = request.GET['expirationDate']
        status          = request.GET['status']

        if not (positionTitle and jobType and cityLocation and stateLocation and preferredSkills and jobDescription and expirationDate and status):
            messages.error(request, "Error. Please enter all fields marked with *")
            valid_input = False

        if valid_input:
            jobPost = JobPost.create(positionTitle,jobType,cityLocation,stateLocation,preferredSkills,jobDescription,expirationDate,status)
            jobPost.save()
            return render(request, 'polls/index.html')

    return render(request, 'polls/newJobPost.html')

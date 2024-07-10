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
        # Receive input from HTTP
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
        # Ensure required field are filled out
        if not (fname and lname and zipcode and skills and experience and username and password1 and password2):
            messages.error(request, "Error. Please enter all fields marked with *")
            valid_input = False
        # Password confirmation should match original
        if password1 != password2:
            messages.error(request, "Error. Passwords do not match")
            valid_input = False
        # Years of experience should be a numerical value
        if not experience.isnumeric():
            messages.error(request, "Error. Please enter a number for years of experience")
            valid_input = False
        # Zip code is also required to be numeric
        if not zipcode.isnumeric():
            messages.error(request, "Error. Please enter a valid numerical zipcode")
            valid_input = False
        # Ensure username is unique
        if not UsernameAvailable(username):
            messages.error(request, "Error. This username is taken")
            valid_input = False
        # Use created templates to create candidate profile and Django user
        if valid_input:
            candidate = CandidateProfile.create(name,bio,zipcode,skills,github,experience,education,username)
            candidate.save()
            print('New Candidate ID:', candidate.id)
            user = User.objects.create_user(username=username, password=password1)
            user.save()
            # Send newly created candidate to landing page
            return render(request, 'polls/index.html')
    
    return render(request, 'polls/newCandidate.html')

def NewRecruiter(request):
    context_object_name = "error_message"
    if 'create_account' in request.GET:
        valid_input = True
        # Receive input from HTTP
        fname      = request.GET['fname']
        lname      = request.GET['lname']
        zipcode    = request.GET['zipcode']
        company     = request.GET['company']
        username   = request.GET['username']
        password1  = request.GET['password1']
        password2  = request.GET['password2']
        # Ensure required fields are filled out
        if not (fname and lname and zipcode and company and username and password1 and password2):
            messages.error(request, "Error. Please enter all fields marked with *")
            valid_input = False
        # Password confirmation should match original
        if password1 != password2:
            messages.error(request, "Error. Passwords do not match")
            valid_input = False
        # Zip code value is numeric
        if not zipcode.isnumeric():
            messages.error(request, "Error. Please enter a valid numerical zipcode")
            valid_input = False
        # Username is not taken
        if not UsernameAvailable(username):
            messages.error(request, "Error. This username is taken")
            valid_input = False
        
        if valid_input:
            # Create recruiter profile and Django user
            recruiter = RecruiterProfile.create(fname,lname,company,zipcode,username)
            recruiter.save()
            print('New Recruiter ID:', recruiter.id)
            user = User.objects.create_user(username=username, password=password1)
            user.save()
            # Send recruiter to landing page
            return render(request, 'polls/index.html')
    
    return render(request, 'polls/newRecruiter.html')

def UsernameAvailable(proposed_username):
    # Check if the proposed username points to either a candidate or recruiter
    c_usernames = CandidateProfile.objects.filter(username=proposed_username)
    r_usernames = RecruiterProfile.objects.filter(username=proposed_username)
    if c_usernames or r_usernames:
        return False
    else:
        return True

def recruiterHome(request):
    #model = RecruiterProfile
    context_object_name = "error_message"
    print(request.GET)
    if 'sign_out' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request,username)
        print('Signed out')
        return HttpResponseRedirect('/polls/index.html')
    return  render(request, 'polls/recruiterHome.html')

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

def NewJobPost(request):
    context_object_name = "newJobPost"
    if 'create_post' in request.GET:
        valid_input = True
        recruiter       = request.session['username']
        positionTitle   = request.GET['positionTitle']
        jobType         = request.GET['jobType']
        cityLocation    = request.GET['cityLocation']
        stateLocation   = request.GET['stateLocation']
        preferredSkills = request.GET['preferredSkills']
        jobDescription  = request.GET['jobDescription']
        expirationDate  = request.GET['expirationDate']
        status          = request.GET['status']

        if not (recruiter and positionTitle and jobType and cityLocation and stateLocation and preferredSkills and jobDescription and expirationDate and status):
            messages.error(request, "Error. Please enter all fields marked with *")
            valid_input = False

        if valid_input:
            jobPost = JobPost.create(recruiter,positionTitle,jobType,cityLocation,stateLocation,preferredSkills,jobDescription,expirationDate,status)
            #jobPost.save()
            return render(request, 'polls/recruiterHome/all',context=context)

    return render(request, 'polls/newJobPost.html')

'''class JobPostList(generic.ListView):
    queryset = JobPost.objects.filter(status=1).order_by('-created_on')
    template_name = 'recruiterHome.html'''



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
from datetime import date


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
            homepage = '/polls/allPosts'
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
    # this page shows all of the posts the recruiter has made and serves as the home login for recruiters
    context_object_name = 'recruiterHomePage'

    # get the user from the request.session
    user = RecruiterProfile.objects.get(pk=request.session['username'])
    # include the user and the posts affiliated with them in the context for the page
    context = {
        'user': user,
        'jobs': user.job_posts.all()
    }
    # see if jobs need to be updated (expired status)
    context['jobs'] = jobUpdate(context['jobs'])

    # sign out button clicked
    if 'signOut' in request.GET:
        # log out
        auth.logout(request)
        # go to the website homepage
        return render(request, 'polls/index.html')
    if 'detailedView' in request.GET:
        jobID = request.GET.get('detailedView')
        job = JobPost.objects.get(pk=jobID)
        request.session['jobDetail'] = jobID
        print("status")
        print(job.status)
        context['jobDetail'] = job
        print(job.interestedCands)
        return redirect('/polls/recruiterJobPostDetail')
    # render the page
    return render(request, 'polls/allPosts.html',context=context)

def RecruiterJobPostDetail(request):
    print("hiiiiii")
    #print(request.GET)
    # get the user from the request.session
    user  = RecruiterProfile.objects.get(pk=request.session['username'])
    jobID = request.session['jobDetail']
    job   = JobPost.objects.get(pk=jobID)
    # include the user and the posts affiliated with them in the context for the page
    context = {
        'user': user,
        'jobDetail': job
    }
    #print(request.GET['update'])
    if 'update' in request.GET:
        print("updating")
        valid_input = True
        positionTitle   = request.GET['positionTitle']
        company         = request.GET['company']
        cityLocation    = request.GET['cityLocation']
        stateLocation   = request.GET['stateLocation']
        expirationDate  = request.GET['expirationDate']
        preferredSkills = request.GET['preferredSkills']
        jobDescription  = request.GET['jobDescription']
        status          = request.GET['status']
        jobType         = request.GET['jobType']

        if valid_input:
            job.positionTitle=positionTitle
            job.jobType=jobType
            job.cityLocation=cityLocation
            job.stateLocation=stateLocation
            job.preferredSkills=preferredSkills
            job.jobDescription=jobDescription
            job.company=company
            job.status=status
            if (expirationDate):
                job.expirationDate=expirationDate
            job.save()
            return redirect('/polls/allPosts')
    if 'delete' in request.GET:
        job.delete()
        return redirect('/polls/allPosts')
    return render(request, 'polls/recruiterJobPostDetail.html',context=context)

def recruiterActivePosts(request):
    context_object_name = 'activePostsRecruiter'
    user = RecruiterProfile.objects.get(pk=request.session['username'])
    context = {
        'user': user,
        'jobs': user.job_posts.all()
    }
    context['jobs'] = jobUpdate(context['jobs'])
    context['jobs'] = getActiveJobs(context['jobs'])
    # sign out button clicked
    if 'signOut' in request.GET:
        # log out
        auth.logout(request)
        # go to the website homepage
        return render(request, 'polls/index.html')
    if 'detailedView' in request.GET:
        jobID = request.GET.get('detailedView')
        job = JobPost.objects.get(pk=jobID)
        request.session['jobDetail'] = jobID
        print("status")
        print(job.status)
        context['jobDetail'] = job
        print(job.interestedCands)
        return redirect('/polls/recruiterJobPostDetail')
    return render(request,'polls/activePostsRecruiter.html',context=context)

def recruiterInactivePosts(request):
    context_object_name = 'inactivePostsRecuiter'
    user = RecruiterProfile.objects.get(pk=request.session['username'])
    context = {
        'user': user,
        'jobs': user.job_posts.all()
    }
    context['jobs'] = jobUpdate(context['jobs'])
    context['jobs'] = getInactiveJobs(context['jobs'])
    # sign out button clicked
    if 'signOut' in request.GET:
        # log out
        auth.logout(request)
        # go to the website homepage
        return render(request, 'polls/index.html')
    if 'detailedView' in request.GET:
        jobID = request.GET.get('detailedView')
        job = JobPost.objects.get(pk=jobID)
        request.session['jobDetail'] = jobID
        print("status")
        print(job.status)
        context['jobDetail'] = job
        print(job.interestedCands)
        return redirect('/polls/recruiterJobPostDetail')
    return render(request,'polls/inactivePostsRecruiter.html',context=context)

def recruiterInterestedPosts(request):
    context_object_name = 'interestedPostsRecruiter'
    user = RecruiterProfile.objects.get(pk=request.session['username'])
    context = {
        'user': user,
        'jobs': user.job_posts.all()
    }
    context['jobs'] = jobUpdate(context['jobs'])
    context['jobs'] = getInterestedJobs(context['jobs'])
    print(getInterestedJobs(context['jobs']))
    # sign out button clicked
    if 'signOut' in request.GET:
        # log out
        auth.logout(request)
        # go to the website homepage
        return render(request, 'polls/index.html')
    if 'detailedView' in request.GET:
        jobID = request.GET.get('detailedView')
        job = JobPost.objects.get(pk=jobID)
        request.session['jobDetail'] = jobID
        print("status")
        print(job.status)
        context['jobDetail'] = job
        print(job.interestedCands)
        return redirect('/polls/recruiterJobPostDetail')
    return render(request,'polls/interestedPostsRecruiter.html',context=context)

def candidateHome(request):
    context_object_name = 'candidateHomePage'
    print(request.session['username'])
    user = CandidateProfile.objects.get(pk=request.session['username'])
    print(user.job_Posts.all())
    print(user.name)
    context = {
        'user': user,
        'jobs': JobPost.objects.order_by('-expirationDate')
    }
    context['jobs'] = jobUpdate(context['jobs'])
    for job in context['jobs']:
        job.compScore = JobCompatibility(request, job)
    if 'signOut' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request)
        print('Signed out')
        return render(request, 'polls/index.html')
    if 'mark_interest' in request.GET:
        jobID = request.GET.get('mark_interest')
        job = JobPost.objects.get(pk=jobID)
        print(job.interestedCands.all())
        job.interestedCands.add(user)
        job.save()
        print(job.interestedCands.all())
    return render(request, 'polls/allPostsCandidate.html',context=context)

def postActiveJobs(request):
    context_object_name = 'candidateActiveJobs'
    user = CandidateProfile.objects.get(pk=request.session['username'])
    context = {
        'user': user,
        'jobs': JobPost.objects.order_by('-expirationDate')
    }
    context['jobs'] = jobUpdate(context['jobs'])
    context['jobs'] = getActiveJobs(context['jobs'])
    for job in context['jobs']:
        job.compScore = JobCompatibility(request, job)
    
    if 'signOut' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request)
        print('Signed out')
        return render(request, 'polls/index.html')
    return render(request,'polls/activePostsCandidates.html',context=context) 
   
def postInactiveJobs(request):
    context_object_name = 'candidateInactiveJobs'
    user = CandidateProfile.objects.get(pk=request.session['username'])
    context = {
        'user': user,
        'jobs': JobPost.objects.order_by('-expirationDate')
    }
    context['jobs'] = jobUpdate(context['jobs'])
    context['jobs'] = getInactiveJobs(context['jobs'])
    for job in context['jobs']:
        job.compScore = JobCompatibility(request, job)
    if 'signOut' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request)
        print('Signed out')
        return render(request, '/polls/index.html')
    return render(request,'polls/inactivePostsCandidates.html',context=context)  

def postInterestedJobs(request):
    context_object_name = 'candidateInterestedJobs'
    user = CandidateProfile.objects.get(pk=request.session['username'])
    context = {
        'user': user,
        'jobs': user.job_Posts.all()
    }
    for job in context['jobs']:
        job.compScore = JobCompatibility(request, job)
    if 'signOut' in request.GET:
        print("hello")
        print(request.session)
        auth.logout(request)
        print('Signed out')
        return render(request, '/polls/index.html')
    return render(request,'polls/interestedPostsCandidates.html',context=context)      
        
def jobUpdate(jobs):
    for job in jobs:
        if job.expirationDate < date.today():
            job.status = 0
            job.save()
    return jobs  

def getActiveJobs(jobs):
    activeJobs = []
    for job in jobs:
        if job.status == 1:
            activeJobs.append(job)
    return activeJobs

def getInactiveJobs(jobs):
    inactiveJobs = []
    for job in jobs:
        if job.status == 0:
            inactiveJobs.append(job)
    return inactiveJobs

def getInterestedJobs(jobs):
    interestedJobs = []
    for job in jobs:
        if job.numInterestCands > 0:
            print("hellllllo")
            interestedJobs.append(job)
    print(interestedJobs)
    return interestedJobs

def markInterested(request):
     user = CandidateProfile.objects.get(pk=request.session['username'])
     job = JobPost.objects.get(pk=pk)
     if 'mark_interest' in request.GET:
        user.favorites.append(job)

def NewJobPost(request):
    context_object_name = "newJobPost"
    print(request.session['username'])
    print("job posts baby")
    print(request.GET)
    recruiter = RecruiterProfile.objects.get(pk=request.session['username'])
    context = {
        'user': recruiter
    }
    if 'create_post' in request.GET:
        print("get it")
        valid_input = True
        positionTitle   = request.GET['positionTitle']
        jobType         = request.GET['jobType']
        cityLocation    = request.GET['cityLocation']
        stateLocation   = request.GET['stateLocation']
        preferredSkills = request.GET['preferredSkills']
        jobDescription  = request.GET['jobDescription']
        company         = request.GET['company']
        expirationDate  = request.GET['expirationDate']

        if not (recruiter and positionTitle and jobType and cityLocation and stateLocation and preferredSkills and jobDescription and company and expirationDate):
            messages.error(request, "Error. Please enter all fields marked with *")
            valid_input = False

        if valid_input:
            print("hello valid")
            jobPost = JobPost.objects.create(recruiter=recruiter,positionTitle=positionTitle,jobType=jobType,cityLocation=cityLocation,stateLocation=stateLocation,preferredSkills=preferredSkills,jobDescription=jobDescription,company=company,expirationDate=expirationDate)
            jobPost.save()
            return redirect('/polls/allPosts')

    return render(request, 'polls/newJobPost.html',context=context)

def JobCompatibility(request, job_post):
    # Overall score broken into chunks such as skills, experience, location, etc.
    # Skill matching: 70%, Location: 10%, Experience: 20%, 
    total = 100
    username = request.session['username']
    user = user = CandidateProfile.objects.get(pk=request.session['username'])
    if not user:
        return 0
    # Match desired skills with declared skills
    candidate_desc = user.skills.replace(' ', '').split(',')
    job_desc = job_post.preferredSkills.replace(' ', '').split(',')
    max_skills = len(job_desc)
    skill_points = 70/max_skills
    # Skill score will max out at 70
    skill_score = 0
    for skill in candidate_desc:
        if skill in job_desc:
            skill_score += skill_points
        if skill_score >= 70-skill_points:
            break
    # Location score maxes out at 10
    # Table to match first digit of zipcode to region of the U.S.
    zip_reference = [
    ['ct','ma','me','nh','nj','pr','ri','vt','vi'],
    ['de','ny','pa'],
    ['dc','md','nc','sc','va','wv'],
    ['al','fl','ga','ms','tn'],
    ['in','ky','mi','oh'],
    ['ia','mn','mt','nd','sd','wi'],
    ['ar','la','ok','tx'],
    ['az','co','id','nm','nv','ut','wy'],
    ['ak','as','ca','gu','hi','or','wa']
    ]
    loc_score = 0
    # if job_post.REMOTE and user.remote:
    #    loc_score = 10
    zip_first_digit = (ord(user.zipcode[0])-ord('0')) - 1
    if job_post.stateLocation.lower() in zip_reference[zip_first_digit]:
        loc_score = 10
    # Experience score maxes out at 20
    exp_score = 0
    if 'senior' not in job_post.positionTitle.lower() and 'junior' not in job_post.positionTitle.lower():
        total = 80
    elif 'senior' in job_post.positionTitle.lower() and user.yearsExp >= 5:
        exp_score = 20
    elif 'junior' in job_post.positionTitle.lower() and user.yearsExp < 5:
        exp_score = 20

    # Return score as decimal
    return round((skill_score + loc_score + exp_score)/total*100)
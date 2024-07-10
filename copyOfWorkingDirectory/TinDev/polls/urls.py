from django.urls import path

from . import views
app_name = 'polls'  # creates a namespace for this app
urlpatterns = [
    path('', views.index, name='index'),
    
    path('newCandidate/', views.NewCandidate, name='newCandidate'),
    path('newRecruiter/', views.NewRecruiter, name='newRecruiter'),
    path('signIn/', views.SignIn, name='signIn'),
    path('newJobPost/', views.NewJobPost, name='newJobPost'),
    path('allPosts', views.recruiterHome, name='allPosts'),
    path('recruiterJobPostDetail', views.RecruiterJobPostDetail, name='recruiterJobPostDetail'),
    path('activePostsRecruiter/', views.recruiterActivePosts, name='activePostsRecuiter'),
    path('inactivePostsRecruiter/', views.recruiterInactivePosts, name='inactivePostsRecruiter'),
    path('interestedPostsRecruiter', views.recruiterHome, name='interestedPostsRecruiter'),
    path('candidateHome/', views.candidateHome, name='candidateHome'),
    path('allPostsCandidate', views.candidateHome, name='allPostsCandidate'),
    path('activePostsCandidates', views.postActiveJobs, name='postActiveJobs'),
    path('inactivePostsCandidates', views.postInactiveJobs, name='postInactiveJobs'), 
    path('interestedPostsCandidates', views.postInterestedJobs, name='interestedPostsCandidates')
]


from django.urls import path

from . import views
app_name = 'polls'  # creates a namespace for this app
urlpatterns = [
    path('', views.index, name='index'),
    
    path('newCandidate/', views.NewCandidate, name='newCandidate'),
    path('newRecruiter/', views.NewRecruiter, name='newRecruiter'),
    path('signIn/', views.SignIn, name='signIn'),
    path('signedIn/', views.SignedIn, name='signedIn'),
    path('signOut/', views.signOut, name='signOut'),
    path('newJobPost/', views.NewJobPost, name='newJobPost'),
    path('recruiterHome/', views.recruiterHome, name='recruiterHome'),
    path('candidateHome/', views.candidateHome, name='candidateHome')
]


from django.http import HttpResponseRedirect
from django.shortcuts import get_object_or_404, render
from django.urls import reverse
from django.views.generic import ListView, DetailView
from .models import Post

# Create your views here.

class IndexView(ListView):
    template_name = 'blog/index.html'
    context_object_name = 'posts'

    def get_queryset(self):
        """Return all the blog posts"""
        return Post.objects.order_by('-pub_date')

class View(DetailView):
    model = Post
    template_name = 'blog/view.html'
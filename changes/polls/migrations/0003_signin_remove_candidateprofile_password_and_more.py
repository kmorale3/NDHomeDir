# Generated by Django 4.1.2 on 2022-11-29 01:26

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('polls', '0002_recruiterprofile'),
    ]

    operations = [
        migrations.CreateModel(
            name='signIn',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
            ],
        ),
        migrations.RemoveField(
            model_name='candidateprofile',
            name='password',
        ),
        migrations.RemoveField(
            model_name='recruiterprofile',
            name='password',
        ),
    ]
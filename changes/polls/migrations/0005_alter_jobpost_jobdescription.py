# Generated by Django 3.2.13 on 2022-12-01 06:26

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('polls', '0004_jobpost'),
    ]

    operations = [
        migrations.AlterField(
            model_name='jobpost',
            name='jobDescription',
            field=models.TextField(max_length=1000),
        ),
    ]

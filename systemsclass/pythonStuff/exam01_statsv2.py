#!/usr/bin/env python3

import csv
import requests

#Constants

URL      = 'https://yld.me/raw/cxEe'
POINTS   = [5]*6
MAX      = sum(POINTS)

# Fetch data

data = requests.get(URL).text.splitlines()
scores   = []
for student in csv.reader(data):
    points = []
    for point in student:
        points.append(float(point))

    scores.append(sum(points))

print(sum(scores))

scores   = map(lambda student: sum(map(float,student)), csv.reader(data))
'''for student in csv.reader(data):
    points = map(float,student)
    scores.append(sum(points))'''

print(sum(scores))

scores = [sum(map(float,student)) for student in csv.reader(data)]
print(sum(scores))

scores = [sum([float(point) for point in student]) for student in csv.reader(data)]
print(sum(scores))


Bs = []
for score in scores:
    if .8*MAX  <= score < .9*MAX:
        Bs.append(score)

print(len(Bs))

Bs = filter(lambda score: .8*MAX  <= score < .9*MAX, scores)
print(len(list(Bs)))

Bs = [score for score in scores if .8*MAX  <= score < .9*MAX]
print(len(list(Bs)))
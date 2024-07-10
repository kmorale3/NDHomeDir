#!/usr/bin/env python3

name   = 'Harry Potter and the Chamber of Secrets'
counts = {}

for letter in name.lower():
    counts[letter] = counts.get(letter, 0) + 1

print (len(counts))
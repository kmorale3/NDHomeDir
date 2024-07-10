#!/usr/bin/env python3

import sys

MAPPING = {
    'a':'4',
    'e':'3',
    'i':'1',
    'o':'0',
}

#this is like cat
for line in sys.stdin:  #O(n)
    line   = line.rstrip() #strips all of the whitespace on the right 
    result = ''

    for letter in line: #O(n)
        letter = MAPPING.get(letter,letter)

        result += letter
    
    print(result)
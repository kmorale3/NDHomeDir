#!/usr/bin/env python3

import collections
import sys

def is_anagram0(s, t):
    #time: O(nlogn)
    #spce: O(n)
    return sorted(s.lower())==sorted(t.lower())

def is_anagram(s, t):
    #time O(n)
    #space O(1) fixed size... scount and tcount are always 26
    scount = [0]*26
    tcount = [0]*26

    for c in s: scount[ord(c.lower())-ord('a')] += 1
    for c in t: tcount[ord(c.lower())-ord('a')] += 1

    return scount == tcount

def main():
    for line in sys.stdin:
        first,second = line.strip().split()

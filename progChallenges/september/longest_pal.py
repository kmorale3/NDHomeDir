#!/usr/bin/env python3

''' 409. Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length 
of the longest palindrome that can be built with those letters.
'''

import collections
import sys
import os

def longest_palindrome(s, p= [], k, greedy=False):
    '''Return the length of the longest possible palindrome from the letters in s.

    :param: p is the current palindrome we are building
    :param: k is the index of the current letter to consider
    '''
    if greedy:
        counts = collections.Counter(s)
        pairs   = sum(count // 2 * 2 for count in counts.values() )
        center  = 1 if any(count % 2 for count in counts.values())
        return pairs + center

    else:
        if k == len(s):                  # base case, used all candidates
            return len(p) if is_palindrome(p) else 0
        else:                            # recursive case
            return max(
            longest_palindrome(s, p, k + 1),
            longest_palindrome(s, p + [s[k]], k + 1)
            )

def is_palindrome(s):
    '''Return whether or not s could be a palindrome
    
    >>> is_palindrome('bcb')
    True 
    
    >>> is_palindrome('bbc')
    True 

    >>> is_palindrome('bcba')
    False
    '''
    counts = collections.Counter(s)
    odds   = sum(1 for count in counts.values() if count % 2)
    return odds <= 1
''' get the counts
    go through
    if odd, add counts -1
    if even, add counts
    add one '''
# Main execution 

def main ():
    '''For each line in stdin, output the longest possible palindrome length.'''
    greedy = os.environ.get("GREEDY", "").lower() in ('true', 'yes','1')
    for line in sys.stdin:
        print(longest_palindrome(line.strip(), greedy=greedy)

if __name__ == '__main__':
    main()
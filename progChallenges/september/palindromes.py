#!/usr/bin/env python3

import collections 
import sys

def is_palindromic(s):
    # example of history
    # time           O(n)
    # space          O(1)

    seen = set()

    for c in s:
        if c in seen:
            seen.remove(c) 
        else:
            seen.add(c)
    
    return len(seen) <= 1
    
def main():
    for word in sys.stdin:
        print('Yes' if is_palindromic(word.rstrip()) else 'No')

if __name__ == '__main__':
    main()
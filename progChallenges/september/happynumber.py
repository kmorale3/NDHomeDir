#!/usr/bin/env python3


import sys

IsHappy = {}

def is_happy(n,seen):
    #Base Cases
    if n ==1:
        return True
    if n in seen:
        return False

    seen.add(n)

    #Recursive
    if not n in IsHappy:
        digits  = map(int, str(n))
        squares = sum(d*d for d in digits)
        IsHappy[n] = is_happy(squares, seen)
   
    return IsHappy[n]
    
def main():
    for n in map(int, sys.stdin):
        print('Yes' if is_happy(n, set()) else 'No')

if __name__ == '__main__':
    main()
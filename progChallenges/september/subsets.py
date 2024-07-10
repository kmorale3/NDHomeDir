#!/usr/bin/env python3

import sys
import itertools

NUMBERS = range(0, 10)

def subsets(s, d, k):
    # s is current subset
    # d is the set of elements to consider (candidates)
    # k is the current element (candidate) we are considering 
    if k == len(d):
        yield s if sum(s) % 3 == 0 else 0
    else:
        yield from subsets(s         , d, k + 1) #skip 
        yield from subsets(s + [d[k]], d, k + 1) #take

def main():
    count = 0
    for length in range(0, len(NUMBERS) + 1):
        for subset in itertools.combinations(NUMBERS, length):
            if not sum(subset) % 3:
                count +=1
    
    print(count)

    for subset in subsets([], NUMBERS, 0):
        print(subset)

if __name__ == '__main__':
    main()
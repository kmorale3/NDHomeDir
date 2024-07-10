#!/usr/bin/env python3


import sys


def find_maximum_contiguous_arry(array):
    # Time   O(n)
    # Space  O(n)
    levels     = {0:0} #levels -> first index
    max_level  = 0
    curr_level = 0

    for index, digit in enumerate(array, 1): #start the enumeration at 1 so that the index starts at 1
        curr_level += 1 if digit == 0 else -1 #ternary       
        if curr_level in levels: #seen it before
            max_level = max(max_level, (index - levels[curr_level]))
        else:
            levels[curr_level] = index

    return max_level
    
def main():
    for line in sys.stdin:
        digits = map(int, line.split())
        print(find_maximum_contiguous_arry(digits))

if __name__ == '__main__':
    main()
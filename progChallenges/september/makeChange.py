#!/usr/bin/env python3

import collections 
import sys

COINS = (25, 10, 5, 1)

def make_change(n):
    # time  O(n)
    # Space O(n)
    # use a generator if you want constant space
    change = []
    for coin in COINS:
        while (n >= coin):
            change.append(coin)
            n -= coin
    return change 

def main():
    for target in map(int, sys.stdin):
        change = map(str, make_change(target))
        print(" + ".join(change))

if __name__ == '__main__':
    main()
#!/usr/bin/env python3
Fibonacci = {0: 0,
             1: 1,
             2: 1}

import sys

def fibonacci(n) :
# this is a great example of memoization

    if not n in Fibonacci:
        Fibonacci[n] = fibonacci(n-1) + fibonacci(n-2)

    return Fibonacci[n]

def main():
    for line in sys.stdin:
        print(fibonacci(int(line)))
    

if __name__ == '__main__':
    main()
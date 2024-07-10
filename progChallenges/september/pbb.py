#!/usr/bin/env python3

# Exercise 05-A: PBB-matched

import sys

# Functions

OPEN_SYMBOLS   = ('(', '[', '{')
CLOSED_SYMBOLS = (')', ']', '}')

def is_pbbmatched(s):
    # TODO: Process string s using a stack to determine if the symbols are balanced 
    # CREATE STACK to track open symbols 
    pbb = []
    # for each symbol in string 
    # if symbol is open: 
    #    push to stack 
    # else: close
    #    check if stack is empty
    #    compare top to symbol
    #    pop from stack 

    for symbol in s:
        if symbol in OPEN_SYMBOLS:
            pbb.push(symbol)
        else:
            if not pbb:
                return False
            index = CLOSED_SYMBOLS.index(symbol)
            if index < 0 or pbb[-1] == OPEN_SYMBOLS[index]:
                return False
            pbb.pop()
    return not pbb

# Main execution

def main():
    for line in sys.stdin:
        line   = line.rstrip()
        result = 'Yes' if is_pbbmatched(line) else 'No'
        print(f'{line:>10}: {result}')

if __name__ == '__main__':
    main()
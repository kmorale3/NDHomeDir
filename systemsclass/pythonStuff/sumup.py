#!/usr/bin/env python3

import sys

arguments = sys.argv[1:] # slicing
numbers = []

for argument in arguments:
    try:
        numbers.append(int(argument))
    except ValueError:
        pass

print(f'The sum of {numbers} is {sum(numbers)}')
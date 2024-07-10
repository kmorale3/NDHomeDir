#!/usr/bin/env python3

import collections
import functools
import sys

Person = collections.namedtuple('Person', 'first last')

def main():
    people = [
        Person(*line.split())
        for line in sys.stdin
    ]

    people = sorted(people, key=lambda p: (p.last,p.first))

    for p in people:
        print(f'{p.first} {p.last}')

if __name__ == '__main__':
    main()
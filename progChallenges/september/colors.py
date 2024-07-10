#!/usr/bin/env python3


import sys

def count_colors(colors):
    '''
    >>> count_colors([0, 1, 2])
    [1, 1, 1]
    >>> count_colors([0, 1, 1, 2, 2, 2])
    [1, 2, 3]
    >>> count_colors([0, 1, 4])
    Traceback (most recent call last):
    ...
    IndexError: list index out of range
    '''
    counts = [0,0,0]
    for c in colors:
        counts[c] += 1
    return counts

def expand_counts(counts):
    '''
    >>> expand_counts([1, 2, 3])
    [0, 1, 1, 2, 2, 2]
    '''
    colors = []
    for color, count in enumerate(counts):
        colors.extend([color]*count)
        #for _ in range(count):
        #    colors.append(color)
    return colors

# Main execution

def main():
    for line in sys.stdin:
        data   = map(int, line.split())
        counts = count_colors(data)
        print(counts) 


if __name__ == '__main__':
    main()
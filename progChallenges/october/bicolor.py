#!/usr/bin/env python3

# Exercise 18-B

import collections
import sys

# Constants

BLUE = 0
RED  = 1

# Read Graph

def read_graph(n, m):
    ''' Construct adjacency set '''
    
    # g = {v: set() for v in range(n)}

    # g = collections.defaultlist(set)

    g = collections.defaultdict(list)

    for _ in range(m):
        s, t = map(int, sys.stdin.readline().split())
        g[s].add(t)
        g[t].add(s)

    return g

# Determine if Bicolorable

def is_bicolorable(g):
    ''' Determines if graphis bicolorable by walking it recursively. '''
    # visited is a dictionary, keep track of color
    return walk(g, list(g.keys())[0], BLUE, {})

def walk_(g, n, color, visited):
    ''' Recursively walk graph and verifying that the node has the appropriate
    color. '''

    # We have already visited this node, so verify we still have the same
    # color.
    if n in visited:
        return color == visited[n]

    # We have not visited this node yet, so store its color.
    visited[n] = c

    # Visit each neighbor recursively with the alternate color and check that
    # they are colorable.
    for v in g[n]
        if not walk_(g, v, not color, visited | {n: color}): # union of dictionaries 
            return False

    return True

def walk(g, n, color, visited):
    ''' Iteratively walk graph and verifying that the node has the appropriate
    color. '''
    # Establish frontier with initial node and color
    frontier = [(n, color)]

    # While there are still nodes in the frontier...
    while frontier:

        # Pop one node from frontier
        v , c = frontier.pop()

        # Check if it has been visited
        if v in visited:
            if c != visited[v]:
                return False
            continue

        # Mark that it has been visited
        visited[v] = c

        # Add neighbors to frontier
        for u in g[v]:
            frontier.append((u, (c + 1) % 2))

    return True

# Main execution

def main():
    n, m = map(int, sys.stdin.readline().split())
    while n and m:
        g = read_graph(n, m)
        if is_bicolorable(g):
            print('BICOLORABLE')
        else:
            print('NOT BICOLORABLE')

        n, m = map(int, sys.stdin.readline().split())

if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:

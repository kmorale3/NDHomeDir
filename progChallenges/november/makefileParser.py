#!/usr/bin/env python3

import collections
import sys

# Graph Structure

Graph = collections.namedtuple('Graph', 'edges degrees')

# Read Graph

def read_graph():
    edges   = collections.defaultdict(set)
    degrees = collections.defaultdict(int)  # 0 by default, once it is inserted 

    # TODO: Read Makefile from stdin
    for line in sys.stdin:
        if ':' not in line:
            continue
        targets, sources = line.split(':', 1)
        targets = targets.split()
        sources = sources.split()

        for target in targets:
            for source in sources:
                edges[source].add(target)
                degrees[target] += 1
                degrees[source]             # initializes to 0 if it doesn't exist, does nothing if it does exist

    return Graph(edges, degrees)

# Topological Sort

def topological_sort(graph):
    # TODO: Perform topological sort
    # add node to frontier if it has degree 0
    frontier = [v for v, d in graph.degrees.items() if d == 0]

    # we want the order
    visited  = []
    while frontier:
        vertex = frontier.pop()

        visited.append(vertex)

        for neighbor in graph.edges[vertex]:
            graph.degrees[neighbor] -= 1
            if not graph.degrees[neighbor]:
                frontier.append(neighbor)
    return visited

# Main Execution

def main():
    graph    = read_graph()
    ordering = topological_sort(graph)
    print(ordering)

    # TODO: Check for cycle, otherwise display ordering

if __name__ == '__main__':
    main()
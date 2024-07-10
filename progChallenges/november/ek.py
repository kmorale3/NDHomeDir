#!/usr/bin/env python3

import sys

def read_graph(stream=sys.stdin)
    n = int(stream.readline())
    if not n:
        return None

    source,target,connections = map(int, stream.readline().split())
    graph = defaultdict(lambda:defaultdict(int))

    for _ in range(connections):
        s,t,w = map(int, stream.readline().split())
        graph[s][t] = w
        graph[t][s] = w

    return source, target, graph

def find_flow(graph, source, target):
    frontier = [... source ...]
    visited  = {}

    while frontier:
        # remove a node BFS

        # check if node in visited
        # check if node is target
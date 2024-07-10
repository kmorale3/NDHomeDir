#!/usr/bin/env python3

# Exercise 17-D: Invert Binary Tree

import collections
import dataclasses
import sys

# Classes

@dataclasses.dataclass
class Node:
    value:  int
    left:   'Node'
    right:  'Node'

# Functions

def read_tree(values, index=0):
    # TODO: Use divide and conquer to parse tree
    # base case: non-existent node
    if index >= len(values):
        return None
    
    # recursive divide and conquer
    return Node(
        value = values[index],
        left  = read_tree(values, 2 * index + 1)
        right = read_tree(values, 2 * index + 2)
    )

def walk_tree(root):
    # TODO: Use BFS Traversal with Queue to create list of values
    queue = collections.deque([root])
    values = []
    while queue:
        node = queue.popleft()
        values.append(node)
        if not node:
            continue
        queue.append(node.left)
        queue.append(node.right)


def dump_tree(root):
    print(','.join(map(str, walk_tree(root))))

def invert_tree(root):
    # TODO: Use divide and conquer to invert binary tree
    # base case: non-existent node
    if root is None:
        return 

    # swap
    root.left, root.right = root.right, root.left
    
    # recursive divide and conquer
    invert_tree(root.left)
    invert_tree(root.right)

# Main Execution

def main():
    for line in sys.stdin:
        values = list(map(int, line.split()))
        root   = read_tree(values)

        invert_tree(root)
        dump_tree(root)

if __name__ == '__main__':
    main()

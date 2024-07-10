#!/usr/bin/env python3

# binary search tree

import sys
from dataclasses import dataclass
from collections import deque 

'''class Node:
    def __init__(sef, value, left=None, right=None):
        self.value = value
        self.left  = left
        self.right = right

'''

@dataclass
class Node:
    value: int
    left:  'Node' = None
    right: 'Node' = None

class Tree(object):
    def __init__(self):
        self.root = None

    def search(self, value):
        return self._search(self.root, value)

    def _search(self, node, value):
        # average time: O(logn)
        # worse   time: O(n)
        # base case: Invalid Node
        if node is None:
            return False
        # base case: Found Value 
        if value == node.value:
            return True
        # recursive: log(n) operations 
        if value < node.value :
            return self._search(node.left, value)
        else:
            return self._search(node.right, value)
    
    def insert(self, value):
        self.root = self._insert(self.root, value)

    def _insert(self, node, value):
        # average time: O(logn)
        # worse   time: O(n)

        # note that duplicates are allowed 

        # base case: Invalid Node
        if node is None:
            return Node(value)

        # recursive: log(n) operations 
        if value <= node.value :
            node.left  = self._insert(node.left, value)
        else:
            node.right = self._insert(node.right, value)

        return node

    def print(self):
        # DFS recursive call
        # self._print(self.root)

        # BFS
        # nodes to visit next
        queue = deque([self.root])

        while queue:
            # get next node to visit
            node = queue.popleft()

            if not node:
                continue

            print(node.value)

            # add children to the queue
            queue.append(node.left)
            queue.append(node.right)


        # DFS iterative
        # nodes to visit next
        queue = [self.root]

        while queue:
            # get next node to visit
            node = queue.pop()

            if not node:
                continue

            print(node.value)

            # add children to the queue
            queue.append(node.right)
            queue.append(node.left)

    def _print(self, node):
        # depth first search, returns an in-order traversal
        # base case: invalid node
        if node is None:
            return

        # recursive
        self._print(node.left)
        print(node.value)
        self._print(node.right)

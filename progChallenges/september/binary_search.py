#!/usr/bin/env python3

# Binary search

def binary_search_iterative(data, target):
    '''
    >>> binary_search_iterative([1,3,4,5,7,9], 3)
    True
    >>> binary_search_iterative([1,3,4,5,7,9], 12)
    False
    >>> binary_search_iterative([1,3,4,5,7,9], 1)
    True
    >>> binary_search_iterative([1,3,4,5,7,9], 9)
    True
    >>> binary_search_iterative([1,3,4,5,7,9], 2)
    False
    '''
    start = 0
    end   = len(data) - 1

    while (start <= end):
        middle    = (start + end) // 2 # 2 slashes does integer division 
        midpoint  = data[middle]

        if (midpoint == target):
            return True
        
        if (midpoint > target):        # Go left
            end   = middle - 1
        else:                          # Go right
            start = middle + 1

    return False

def binary_search_recursive(data, target, start = None, end = None):
    '''
    >>> binary_search_recursive([1,3,4,5,7,9], 3)
    True
    >>> binary_search_recursive([1,3,4,5,7,9], 12)
    False
    >>> binary_search_recursive([1,3,4,5,7,9], 1)
    True
    >>> binary_search_recursive([1,3,4,5,7,9], 9)
    True
    >>> binary_search_recursive([1,3,4,5,7,9], 2)
    False
    '''

    # initialize start and end
    # ternary expression 
    start = 0             if start is None else start
    end   = len(data) - 1 if end   is None else end

    #base case: boundaries cross
    if start > end:
        return False

    middle    = (start + end) // 2 
    midpoint  = data[middle]

    # base case: target found
    if midpoint == target:
        return True 
    
    # recursive step
    if midpoint > target:     # Go left
        return binary_search_recursive(data, target, start, middle - 1)
    else:                     # Go right
        return binary_search_recursive(data, target, middle + 1, end)
    
    return False 

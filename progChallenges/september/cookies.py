#!/usr/bin/env python3

# Exercise 14-A: Cookies

import sys

# Functions

def readline():
    # TODO: Read a line from stdin
    return sorted(map(int, sys.stdin.readline().split()), reverse = True)


def feed_children(children, cookies):
    # TODO: Return number of children fed with cookies
    count = 0
    while (children and cookies):
        child  = children.pop(0)        # hungriest child
        cookie = cookies[0]             # largest cookie
        if cookie >= child:             # cookie satisfies child
            count += 1                  # give cookie to child 
            cookies.pop(0)              # remove cookie

    return count

# Main execution

def main():
    while (children := readline()) and (cookies := readline()):
        print(feed_children(children, cookies))

if __name__ == '__main__':
    main()
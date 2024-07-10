#!/usr/bin/env python3

# humane squirrel trapping 

# table[r,c] = max(table[r-1, c], table[r, c-1]) + grid[r,c]
# add in padding of 0s

# Notes:
#
#   1. Each S(r, c) contains the optimal solution for that square.
#
#   2. Final solution is in the bottom right corner: S(n, n).
#
#   3. Building the table does not reveal what the path is, just what the
#   maximum squirrel population is.

import sys

# Functions

def read_grid(n):
    grid = [[0 for _ in range(n + 1)]]      # Pad grid
    for _ in range(n):
        grid.append([0] + list(map(int, sys.stdin.readline().split())))
    return grid

def hunt_squirrels(grid, n):
    # TODO: 1. Initialize table
    table = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    # TODO: 2. Table[row][col] = Grid[row][col] + max(from_left, from_above)
    #
    #   S(r, c) = Max(S(r, c - 1), S(r - 1, c)) + G(r, c)
    #

    # TODO: 3. Use table result
    for r in range(1, n + 1):
        for c in range(1, n + 1):
            table[r][c] = max(table[r-1][c], table[r][c-1]) + grid[r][c]
    
    return table

def find_path(grid, n, table):
    path = []
    r, c = n, n
    while r > 0 and c > 0:
        path.append(grid[r][c])
        
        if table[r][c] - grid[r][c] == table[r][c-1]:
            c = -1
        else:
            r -= 1

    path.reverse()
    return path 

def main():
    while True:
        try:
            n = int(sys.stdin.readline())
        except ValueError:
            break

        grid = read_grid(n)
        table = hunt_squirrels(grid, n)
        path  = find_path(grid, n, table)
        print(path)
        print(table[n][n])

# Main execution

if __name__ == '__main__':
    main()
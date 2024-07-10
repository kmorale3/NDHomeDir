#!/usr/bin/env python3
import math
def find_squares(start, end):
    squares = []
    for number in range(start, end):
        if math.sqrt(number) == int(math.sqrt(number)):
            squares.append(number)
    return squares

def find_map(start,end): 
    return filter(lambda number:math.sqrt(number) == int(math.sqrt(number)), range(start,end))

def find_list(start,end):
    return [number for number in range(start, end) if math.sqrt(number) == int(math.sqrt(number)) ]

def find_gen_yield(start, end):
    for number in range(start, end):
        if math.sqrt(number) == int(math.sqrt(number)):
            yield number

def find_gen(start, end):
    return (number for number in range(start, end) if math.sqrt(number) == int(math.sqrt(number)))


print(find_squares(1,30))
print(' '.join(str(ob) for ob in find_map(1,30)))
print(find_list(1,30))
print(' '.join(str(ob)for ob in find_gen_yield(1,30)))
print(' '.join(str(ob)for ob in find_gen(1,30)))



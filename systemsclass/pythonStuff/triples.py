#!/usr/bin/env python3

def triples_gen(sequence):
    for i in sequence:
        yield i * 3

for i in triples_gen([1,2,3]):
    print(i)


#!/usr/bin/env python3

numbers = range(0, 10)

doubled = map(lambda n: n*2, numbers)
doubled1 = []
for n in numbers:
    doubled1.append(n*2)

doubled2 = [n * 2 for n in numbers]
selected2 = [d for d in doubled2 if not d % 4]

selected = filter(lambda d: not d % 4, doubled)
selected1 = []
for d in doubled1:
    if not d % 4:
        selected1.append(d)
        
for s in selected:
    print(s)
for s in selected1:
    print(s)
for s in selected2:
    print(s)
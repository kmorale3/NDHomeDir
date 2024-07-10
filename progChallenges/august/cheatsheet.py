#!/usr/bin/env python3

#create dynamic array
v = [1,2,3]

#append to the back 
v.append(4)

#preprend to the front 
v.insert(0,0)

#display number of elements
print(len(v))

#traverse elements
for e in v:
    print(e)

for i, e in enumerate(v):
    print(f'{i}. {e}')
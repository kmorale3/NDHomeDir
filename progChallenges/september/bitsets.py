#!/usr/bin/env python3

elements = (1,2,4)
#initialize bitst
bitset = 0

# add elements to bitset
for i in elements:
    bitset = bitset | (1 << i)

formatted = f'{bitset:08b}'
print(f'{bitset:x}')        # hex
print(f'{bitset:08b}')      # binary 

# test for elements  bitset
for i in range(6):
    if bitset & 1<<i:
        print(f'{i} in bitset')

# remove 
for i in elements:
    bitset = bitset & ~(1<<i)

print(f'{bitset:08b}')      # binary 
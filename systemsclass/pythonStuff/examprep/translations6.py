#!/usr/bin/env python3

import os
dictionary = {}
for line in os.popen('ls -l /etc'):
    data = line.rstrip().split()[1]
    dictionary[data] = dictionary.get(data, 0) + 1 

for key, value in sorted(dictionary.items(), key=lambda p: p[0] ):
    print(f'{value:7} {key}')
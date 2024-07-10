#!/usr/bin/env python3

import re 

'''regex = r''

for line in open('/etc/passwd'):
    data = line.split()[0]
    if data.endswith('d')'''

print(sum(1 for line in open('/etc/passwd') if line.split(':')[0].endswith('d')))
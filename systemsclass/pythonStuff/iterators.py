#!/usr/bin/env python3

import os

for i in [1, 2, 3, 4]:
    print(i)

for c in 'samuel':
    print(c)

for key, value in os.environ.items():
    print(key, value)

for line in open('/etc/passwd'):
    print(line.rstrip())
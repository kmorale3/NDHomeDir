#!/usr/bin/env python3
import re

regex = r'^[0-9]{2}$'

'''for line in open('/etc/passwd'):
    data = line.split(':')[2].rstrip()
    if re.findall(regex, data):
        #print(data)'''

results = sorted(set(line.split(':')[2] for line in open('/etc/passwd') if re.findall(regex, line.split(':')[2])))
for result in results:
    print(result)
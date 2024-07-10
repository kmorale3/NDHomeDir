#!/usr/bin/env python3
import re
import os

regex = r'.*\((.*)\).*'
snips=[]
for line in os.popen('who'):
    data = re.sub(regex,r'\1',line.rstrip())
    if data not in snips:
        snips.append(data)
for snip in sorted(snips):
    print(snip)





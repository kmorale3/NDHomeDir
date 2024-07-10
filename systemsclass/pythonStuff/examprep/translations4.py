#!/usr/bin/env python3
import re
import requests
regex = r'^B.*'
data = requests.get('http://yld.me/raw/lmz').text.rstrip()
'''print(data.split('\n')[0].split(',')[1])
for line in data.split('\n'):
    line = line.rstrip()
    print(line.split(',')[1])'''
#results = sorted(line.split(',')[1] for line in data.split('\n') if re.findall(regex, line.split(',')[1]))
for result in sorted(line.split(',')[1] for line in data.split('\n') if re.findall(regex, line.split(',')[1])):
    print(result)
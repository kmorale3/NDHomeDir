#!/usr/bin/env python3
import re
import requests
data = requests.get('http://yld.me/raw/lmz').text
regex = r'^[^jfs].*'

results = (line.split(',')[0] for line in data.split('\n') if re.findall(regex, line.split(',')[0]))
for result in results:
    print(result)
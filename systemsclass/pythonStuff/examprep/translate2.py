#!/usr/bin/env python3

#curl -sL https://yld.me/raw/fDIO | sort -t , -k 2 | cut -d , -f 3 | tr a-z A-Z

import requests

response = requests.get('https://yld.me/raw/fDIO').text
results = {}
for line in response.split('\n'):
    try:
        data = line.split(',')[1]
    except IndexError:
        break
    name = line.split(',')[2]
    results[name]=data


for key, val in sorted(results.items(), key = lambda r: r[1]):
    answer = key.upper()
    print(answer)


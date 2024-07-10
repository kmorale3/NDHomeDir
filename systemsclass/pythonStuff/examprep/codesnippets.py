#!/usr/bin/env python3
import os
import requests
import sys
nums = [num for num in range(30)]
'''for num in nums:
    print(num)'''
print(nums[0:10])
print(len(nums))
print(max(nums))
print(min(nums))

string = "Let this promise in me start, Like an anthem in my heart"
print(string.split()[0])
print(string.split()[-1])
'''for line in os.popen('ps aux'):
    print(line)'''

response = requests.get('http://yld.me/raw/fDIO')
print(response.text)

'''for line in sys.stdin:
    print(line)'''

for arg in sys.argv[1:]:
    try:
        print(os.environ[arg])
    except:
        print(arg)
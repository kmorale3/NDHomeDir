#!/usr/bin/env python3

import os
import re
import sys

import requests

# Functions

def usage(status=0):
    print(f'''Usage: {os.path.basename(sys.argv[0])} [flags]
    -c      CITY    Which city to search
    -s      STATE   Which state to search (Indiana)''')
    sys.exit(status)

def zipcodes(city, state):
    url   = f'https://www.zipcodestogo.com/{state}/'
    regex = r'/([^/]+)/[A-Z]{2}/([0-9]{5})/">'
    #response = os.popen(f'curl -sL {url}')
    headers = {'User-Agent':__name__}
    response = requests.get(url, headers=headers)
    matches = re.findall(regex, response.text)

    for current, zipcode in matches:
        if city is None or city == current:
            print(zipcode)



def main():
    state = 'Indiana'
    city = None
    
    arguments = sys.argv[1:]

    while arguments and arguments[0].startswith('-'):
        argument = arguments.pop(0)
        if argument == '-c':
            city  = arguments.pop(0)
        elif argument == '-s':
            state = arguments.pop(0)
        elif argument == '-h':
            usage(0)
        else:
            usage(1)

    zipcodes(city, state) 

# Main execution

if __name__ == '__main__':
    main()

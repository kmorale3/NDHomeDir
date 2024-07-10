#!/usr/bin/env python3

import pprint
import re
import sys

import requests

# Constants

URL      = 'https://en.wikipedia.org/w/api.php' # Discuss: APIs
PARAMS   = {
    'action'  : 'query', 
    'list'    : 'search', 
    'format'  : 'json', 
    'srsearch': sys.argv[1]
}

# Main Execution

def get_wordcount(a):
    return a['wordcount']

def main():
    response   = requests.get(URL, params=PARAMS) # Review: keyword arguments
    data     = response.json()
    articles = data['query']['search']               # Discuss: json
    key_func = lambda a: a['wordcount']

    articles = sorted(articles, key=key_func, reverse=True)
    for index, article in enumerate(articles[:5], 1):
        if index > 1:
            print()
        title   = article['title']
        snippet = re.sub(r'<[^>]*>','',article['snippet'])
        print(f'{index:4}.\t{title}\n\t{snippet}')

if __name__ == '__main__':
    main()

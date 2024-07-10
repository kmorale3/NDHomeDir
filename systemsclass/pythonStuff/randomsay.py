#!/usr/bin/env python3

import os
import random                                   # Discuss: random module
import sys

# Constants
                                                # Discuss: set data structure
NSFW = {'bong', 'sodomized', 'kiss', 'head-in', 'telebears'}

# Main Execution

def main():
    cows = []

    for index, line in enumerate(os.popen('cowsay -l')):
        if index == 0:
            continue

        for cow in line.split():
            if cow not in NSFW:
                cows.append(cow)

    chosen = random.choice(cows)
    os.system(f'cowsay -f {chosen}')

if __name__ == '__main__':
    main()
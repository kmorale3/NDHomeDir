#!/usr/bin/env python3

def permutations(p,c):
    '''
    p: current permuation
    c: set of candidates
    '''
    #base case: we run out of candidates
    if not c:
        yield p
    else:
        for e in sorted(c):
            yield from permutations( 
                p + e,  #add element to permutation 
                c - {e} #remove element from candidates 
            )

def main():
    for p in permutations('',set('ABC')):
        print(''.join(p))

if __name__ == '__main__':
    main()
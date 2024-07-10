#!/usr/bin/env python3

def fizzbuzz(start=1, end=20): #default arguments
    '''
    Print fizzbuzz from start to end.
    
    >>> fizzbuzz(1,5)
    1
    2
    Fizz
    4
    Buzz
    '''
    for number in range(start, end + 1):
        if (((number % 3) == 0) and ((number % 5)==0)):
            print('FizzBuzz')
        elif ((number %3) == 0):
            print('Fizz')
        elif ((number %5) == 0):
            print('Buzz')
        else:
            print(number)

if __name__ == '__main__':            
    fizzbuzz()   


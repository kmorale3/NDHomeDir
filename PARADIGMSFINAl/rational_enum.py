#!/usr/bin/env python3

# Katie Morales
# Programming Paradigms Final Exam
# iterator rational enumeration

class rational_enum:
    def __init__(self,n):
        self.i    = 1
        self.n    = n
    
    def __iter__(self):
        return self

    def __next__(self):
        while self.i <= self.n:
            i = self.i 
            self.i += 1
            digit1  = 2
            digit2  = 2
            myRange = 2
            # first is 2/2
            if i == 1: return(f'{digit1}/{digit2}')
            # generate ration numbers from each other
            for k in range(1,i):
                # digit 2 is increasing and digit 1 is decreasing
                if ((myRange//2) % 2 == 1):
                    # update range
                    if (digit2 == myRange):
                        myRange += 2
                        digit2  += 2
                    else: 
                        digit1 -= 2
                        digit2 += 2
                # digit 1 is increasing and digit 2 is decreasing
                else:
                    #update range
                    if (digit1 == myRange):
                        myRange += 2
                        digit1  += 2
                    else:
                        digit1 += 2
                        digit2 -= 2
            # return the string
            return(f'{digit1}/{digit2}')
        else:
            raise StopIteration()

'''for x in rational_enum(6):
	print(x)'''
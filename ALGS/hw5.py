import sys
import string

def main():

    # numbers is the input: a sequence of distinct positive integers separated by spaces
    numbers = [int(n) for n in sys.stdin.readline().split()]

    # how many numbers were inputted
    length = len(numbers)

    total = sum(numbers)
    # if the total sum is odd, then there cannot be a valid packing
    if total % 2 == 1:
        print("no packing")
        return 

    # this is the number our 2 subsets must sum to 
    # make sure the type is an inte
    target = total // 2

    # 0 means there is no solution, 1 means there is 
    SOLUTION = [[0] *(target+1) for i in range(length+1)]

    # we are initializing to -1 since there are not any solutions yet
    # 0 will represent the sum coming from horizontal movement (not adding the item to the subset)
    # 1 will represent the sum coming from a diagonal movement (adding the item to the subset)
    DIRECTION = [[0] *(target+1) for i in range(length+1)]

    # empty set sums to 0 
    SOLUTION[0][0] = 1

    # still empty set sums to 0 by horizontal movement (not adding the next element to the subset
    SOLUTION[1][0] = 1
    DIRECTION[1][0] = 0

    # empty set + first number sums to value of first number by diagonal movement
    SOLUTION[1][numbers[0]] = 1
    DIRECTION[1][numbers[0]] = 1

    for i in range(2,length):
        for k in range(0, target + 1):
            # horizontal movement, already found solution
            # does not need to include new number 
            if SOLUTION[i-1][k] == 1:
                SOLUTION[i][k] = 1
                DIRECTION[i][k] = 0
            # we only want to check for a diagonal movement for sums greater than element being evaluated
            if numbers[i - 1] <= k :
                # in order to optimize the algorithm, we will choose the diagonal movement (adding to the subset) over the horizontal movement (not adding the number)
                # EXCEPT: if we have already reached the target sum, we do not want to prioritize diagonal movement
                # we should choose to keep the subset that already sums to the target (horizontal movement)
                if SOLUTION[i][k] == 1 and k == target:
                    continue
                if SOLUTION[i-1][k-numbers[i - 1]] == 1:
                    SOLUTION[i][k] = 1
                    DIRECTION[i][k] = 1

    # check for the final item
    # it should have a solution coming horizontally and diagonally, meaning it should be in one subset
    if SOLUTION[length - 1][target] == 1 and (numbers[length - 1] <= target):
        if SOLUTION[length - 1][target-numbers[length - 1]] != 1:
            print("no solution")
            return False
    else:
        print("no solution")
        return False

    # start S1 on the path excluding the last item
    indexS1Sum = target
    S1 = []
    # start S2 on the path including the last item
    indexS2Sum = target - numbers[length - 1]
    S2 = [numbers[length - 1]]

    # BACKTRACKING 
    # we are going back to construct the subsets
    for i in range(length-1, 0, -1):
        # earlier we had to make a choice of going horizontal or diagonal
        # however, in the case where we are at the same spot, we have to go horizontal and diagonal, even if that is not what was set 
        if indexS1Sum == indexS2Sum:
            indexS1Sum -= numbers[i - 1]
            S1.append(numbers[i - 1])
            continue
        # S1 came from diagonal
        # S2 came from horizontal
        if DIRECTION[i][indexS1Sum] == 1 and DIRECTION[i][indexS2Sum] == 0:
            indexS1Sum -= numbers[i - 1]
            S1.append(numbers[i - 1])
        # S2 came from diagonal
        # S1 came from horizontal    
        elif DIRECTION[i][indexS1Sum] == 0 and DIRECTION[i][indexS2Sum] == 1:
            indexS2Sum -= numbers[i - 1]
            S2.append(numbers[i - 1])
        # there is not a solution if there is not a horizontal movement and a vertical movement
        else:
            print("no solution ")
            return False

    # if the lengths are not equal to the original subset length, not a valid solution
    # if each of the final sums are not 0, not a valid solution
    if (len(S1) + len(S2)) != length or (indexS1Sum != 0 or indexS2Sum != 0):
        print("no solution")
        return False

    # print the solution
    print("there is a solution")
    print(f'sum: {sum(S1)}, subset: {S1}')
    print(f'sum: {sum(S2)}, subset: {S2}')

if __name__ == '__main__':
    main()
#!/usr/bin/env python3

def compute_table_backward(n, coins=COINS):
    # 1 initiaize the table 
    table = [0] * (n + 1) # pad the table 

    # 2 initialize the base cases
    for coin in coins:
        table[coin] = 1

    # 3 construct the table with the recursive relationship 
    # 
    # table[i] = min(table[i - 1], table[i - 3], table[i - 4]) + 1
    for i in range(1, n + 1):
        if table[i]:
            continue  
        table[i] = min(table[i - c] for c in coins if (i - c) >= 0) + 1

    return table

def compute_table_forward (n, coins=COINS):
# 1 initiaize the table 
    table = [n] * (n + 1) # pad the table 

    # 2 initialize the base cases
    for coin in coins:
        table[coin] = 1

    # 3 construct the table with the recursive relationship 
    # 
    # table[i + coin] = min(Table[i + coin], Table[i] + 1)

    for i in range(1, n + 1):
        for coin in coins:
            if (i + coin) > n:
                continue
            table[i + coin] = min(Table[i + coin], Table[i] + 1)
    return table

def main():
    #pre-compute all solutions up to 100
    table = compute_table(100)

if __name__ == '__main__':
    main()
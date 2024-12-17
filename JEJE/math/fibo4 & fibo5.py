# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
MAX = 10000

dp = [-1 for _ in range(MAX+1)]

def fib(n):
    stack = []
    
    stack.append(n)
    while len(stack) > 0:
        n = stack.pop()
        
        if dp[n] == -1:
            if n % 2 == 0:
                tmp = n // 2
                if dp[tmp] == -1:
                    stack.append(n)
                    stack.append(tmp)
                else if dp[tmp - 1] == -1:
                    stack.append(n)
                    stack.append(tmp - 1)
                else:
                    dp[n] = ((2 * dp[tmp - 1] + dp[tmp]) * dp[tmp])
            else:
                tmp = (n + 1) // 2
                if dp[tmp] == -1:
                    stack.append(n)
                    stack.append(tmp)
                else if dp[tmp - 1] == -1:
                    stack.append(n)
                    stack.append(tmp - 1)
                else:
                    dp[n] = (dp[tmp] * dp[tmp] + dp[tmp - 1] * dp[tmp - 1])
    
    return dp[n]

if __name__ == "__main__":
    n = int(input())
    print(fib(n))
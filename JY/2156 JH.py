# 포도주 시식

import sys
n = int(sys.stdin.readline().rstrip())
wine = [0] + [int(sys.stdin.readline().rstrip()) for _ in range(n)]


def max_wine(wine):
    dp = [0]*(n+1)
    dp[1] = wine[1]

    if n > 1:
        dp[2] = wine[1] + wine[2]

    for i in range(3, n+1):
        """
        print(dp[i-4] + wine[i-1] + wine[i], dp[i-2] +
              wine[i], dp[i-3] + wine[i-1] + wine[i], end="\t\t")
        print(
            f"dp[{i}] = {max(dp[i-4] + wine[i-1] + wine[i], dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i])}")"""
        # X
        dp[i] = max(dp[i-1],
                    # X O O
                    dp[i-2] + wine[i],
                    # O X O
                    dp[i-3] + wine[i-1] + wine[i])

    print(dp)

    return max(dp)


"""def max_wine2(wine):
    dp2 = [0]*(n+1)
    dp2[1] = wine[1]

    if n > 1:
        dp2[2] = wine[1] + wine[2]

    for i in range(3, n+1):
        print(dp2[i-2] + wine[i], dp2[i-3] + wine[i-1] + wine[i], end="\t")
        print(
            f"dp[{i}] = {max(dp2[i-4] + wine[i-1] + wine[i], dp2[i-2] + wine[i], dp2[i-3] + wine[i-1] + wine[i])}")
        print(i)
        dp2[i] = max(dp2[i-2] + wine[i], dp2[i-3] + wine[i-1] + wine[i])
    print(dp2)

    return max(dp2)"""


print()
print(max_wine(wine))
"""
print()
print(max_wine2(wine))"""

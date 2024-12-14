# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
arr = [1]

def fill_to_n(n):
    while (2 ** len(arr)) < n:
        arr.append(arr[-1]*3)

if __name__ == '__main__':
    while True:
        N = int(input())
        if N == 0:
            break

        fill_to_n(N)

        ans = []
        for i in range(len(arr)):
            if N-1 & (1 << i):
                ans.append(f"{arr[i]}")
                ans.append(f", ")
        if ans:
            ans.pop()
            print("{ " + "".join(ans) + " }")
        else:
            print("{ }")

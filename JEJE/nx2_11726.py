# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
import sys
n = int(sys.stdin.readline()[:-1])

arr = [0] * 1003
arr[1] = 1
arr[2] = 2

for i in range(3, n+1):
    arr[i] = arr[i-1] + arr[i-2]
    arr[i] %= 10007

print(arr[n])
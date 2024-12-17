# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
import sys

if __name__ == '__main__':
    n = int(sys.stdin.readline().rstrip())
    arr = [0] * 10

    while n > 0:
        arr[n % 10] += 1
        n //= 10
    
    arr[6] = (arr[6] + arr[9] + 1) // 2
    arr[9] = 0

    sys.stdout.write(str(max(arr)))
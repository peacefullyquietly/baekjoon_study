# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
import sys

N = int(sys.stdin.readline()[:-1])
i = 2
while N != 1:
    if N%i == 0:
        N //= i 
        sys.stdout.write(f"{i}\n")
    else:
        i += 1
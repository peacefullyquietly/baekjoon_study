# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
import sys
correct = []
K = int(sys.stdin.readline()[:-1])
for _ in range(K):
    N = int(sys.stdin.readline()[:-1])
    if N != 0:
        correct.append(N)
    else:
        correct.pop()
sys.stdout.write(f'{sum(correct)}\n')
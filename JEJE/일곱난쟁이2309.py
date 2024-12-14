# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
nan = []

def solve(nan):
    for i in nan:
        for j in nan:
            nani = nan[:]
            nani.remove(i)
            if i != j:
                nani.remove(j)
            if sum(nani) == 100:
                nani.sort()
                return nani

for _ in range(9):
    nan.append(int(input()))

for i in solve(nan):
    print(i)
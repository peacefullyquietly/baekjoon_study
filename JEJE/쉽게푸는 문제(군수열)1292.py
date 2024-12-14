# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
A, N = map(int,input().split())
goon = []
for i in range(46):
    for j in range(i):
        goon.append(i)
goon = goon[A-1:N]
print(sum(goon))
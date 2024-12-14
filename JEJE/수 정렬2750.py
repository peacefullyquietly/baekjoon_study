# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
import sys
N =int(input())
if N != 1:
    un_sorted = []
    for _ in range(N):
        un_sorted.append(int(sys.stdin.readline()[:-1]))
    for _ in un_sorted:
        for i, word in enumerate(un_sorted):
            if i==0:
                if word > un_sorted[i+1]:
                    un_sorted[i] = un_sorted[i+1]
                    un_sorted[i+1] = word
            elif i>0:
                if word < un_sorted[i-1]:
                    un_sorted[i] = un_sorted[i-1]
                    un_sorted[i-1] = word
    for i in un_sorted:
        print(i)
else:
    print(sys.stdin.readline()[:-1])
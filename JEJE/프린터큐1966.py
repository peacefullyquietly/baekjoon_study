# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
# T = int(input())
N, M = map(int, input().split())
impo = list(map(int, input().split()))
doc = []
for i in enumerate(impo, start=1):
    doc.append(list(i))
BIG = sorted(doc[0:], key = lambda x : x[1])[-1]

# for i in doc:
#     if i[1]<
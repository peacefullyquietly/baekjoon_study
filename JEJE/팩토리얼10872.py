# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
def pac(n, p = 1):
    if n <= 0:
        return p
    pac(n-1, n*(n-1))

answer = pac(int(input()))
print(answer)
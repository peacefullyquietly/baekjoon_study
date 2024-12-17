# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
import sys

def input():
    return sys.stdin.readline().rstrip()

def print(*args, end='\n', sep=' '):
    args = list(map(lambda x: str(x)+sep, args))
    sys.stdout.write(sep.join(args).rstrip(sep))
    sys.stdout.write(end)

l = list(map(int, input().split()))
print("Yes" if l[0]*100 >= l[1] else "NO")
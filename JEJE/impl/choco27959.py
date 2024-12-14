import sys

def input():
    return sys.stdin.readline().rstrip()

def print(*args, end='\n', sep=' '):
    args = list(map(lambda x: str(x)+sep, args))
    sys.stdout.write(sep.join(args).rstrip(sep))
    sys.stdout.write(end)

l = list(map(int, input().split()))
print("Yes" if l[0]*100 >= l[1] else "No")
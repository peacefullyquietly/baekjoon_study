import sys
input = sys.stdin.readline
cnt = 0
users = set()

N = int(input())
for i in range(N):
    log = input().rstrip()
    if log == "ENTER":
        cnt += len(users)
        users.clear()
    else:
        users.add(log)

cnt += len(users)
print(cnt)

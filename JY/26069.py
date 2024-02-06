import sys
input = sys.stdin.readline

N = int(input())
center = ""
user = dict()
for i in range(N):
    a, b = map(str, input().split())
    if a in user:
        user[a] += [b]
    else:
        user[a] = [b]
    if b in user:
        user[b] += user[a]
    else:
        user[b] = user[a]
# print(user)

rainbow_dance = set()
print(set(user["ChongChong"]))
print(len(set(user["ChongChong"])))

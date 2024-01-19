import sys
input = sys.stdin.readline
N, M = list(map(int, input().split()))

pokedex = {}
for i in range(N):
    tmp = input().rstrip()
    pokedex[tmp] = i + 1

reverse_pokedex = dict(map(reversed, pokedex.items()))

for i in range(M):
    tmp = input().rstrip()
    if tmp.isdecimal():
        print(reverse_pokedex.get(int(tmp)))
    else:
        print(pokedex.get(tmp))

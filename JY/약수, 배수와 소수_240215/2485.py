"""
# min_dis를 미리 구해놓고, 1씩 빼는 코드...
# 위치 정보는 10억까지 받을 수 있어서 너무 느림
import sys
input = sys.stdin.readline

N = int(input())
trees = []

# 모든 가로수가 같은 간격.
# 추가되는 나무는 기존의 나무들 사이에만 심을 수 있음

for i in range(N):
    tree = int(input())
    trees.append(tree)
# print(trees)

# 최소 간격을 구해야할 것 같음
min_dis = 1000000001
for i in range(0, len(trees)-1):
    if trees[i+1] - trees[i] < min_dis:
        min_dis = trees[i+1] - trees[i]

# print(min_dis)
ans = 0
i = 0
while i < len(trees)-1:
    r = (trees[i+1] - trees[i])
    if r % min_dis != 0:
        min_dis -= 1
        i = 0
        ans = 0
    else:
        ans += (r // min_dis) - 1
        i += 1
print(ans)

"""

import sys
input = sys.stdin.readline

N = int(input())
trees = []

# 유클리드 호제법으로 최대공약수 구하기


def Euclidean(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


# 모든 가로수가 같은 간격.
# 추가되는 나무는 기존의 나무들 사이에만 심을 수 있음
for i in range(N):
    tree = int(input())
    trees.append(tree)

# 각각의 최소 간격을 distances에 미리 계산하여놓음
min_dis = 1000000001
distances = []
for i in range(0, len(trees)-1):
    distances.append(trees[i+1] - trees[i])


gcd_set = list(set(distances))

for i in range(len(gcd_set)-1):
    gcd = Euclidean(gcd_set[i], gcd_set[i+1])
    if gcd < min_dis:
        min_dis = gcd

ans = 0
i = 0
while i < len(trees)-1:
    r = (trees[i+1] - trees[i])
    if r // min_dis != 0:
        ans += r // min_dis - 1
    else:
        ans += r // min_dis
    i += 1
print(ans)

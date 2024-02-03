import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
balloons = deque()
balloons_idx = deque()
number = list(map(int, input().split()))
for i in range(N):
    balloons.append(number[i])
    balloons_idx.append(i+1)

# 우선, 제일 처음에는 1번 풍선을 터뜨린다.
# 다음에는 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다.
# 양수가 적혀 있을 경우에는 오른쪽으로, 음수가 적혀 있을 때는 왼쪽으로 이동한다.
# 이동할 때에는 이미 터진 풍선은 빼고 이동한다.

# print(balloons)
# print(balloons_idx)

while len(balloons) > 1:
    target = balloons[0]
    target_idx = balloons_idx[0]
    balloons.popleft()
    balloons_idx.popleft()
    if target > 0:
        balloons.rotate(-(target-1))
        balloons_idx.rotate(-(target-1))
    else:
        balloons.rotate(-target)
        balloons_idx.rotate(-target)
    # print(balloons)
    # print(balloons_idx)
    print(target_idx, end=" ")
    """print(target_idx, end=" ")"""
print(balloons_idx[0])

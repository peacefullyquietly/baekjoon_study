import sys
from collections import deque
input = sys.stdin.readline

N, M = list(map(int, input().split()))
num_list = [(i+1) for i in range(N)]
num_list = deque(num_list)
# print(num_list)
# 초기 뽑아야하는 수들의 위치임
pick_nums = deque(list(map(int, input().split())))
# print(pick_nums)

# 2번, 3번 연산의 최솟값이어야 함
# 방향을 어떻게해야 최소로 쓰지...이진???
# 그냥 다 계산해서 왼쪽/오른쪽 비교해서 굴릴까
# 더 적은거를 cnt에 넣는식으로
cnt = 0
while (len(pick_nums) > 0):
    tmp = 0
    flag = True
    while (num_list[0] != pick_nums[0]):
        tmp += 1
        """print(
            f'tmp: {tmp}, num_list[-tmp] : {num_list[-tmp]}, num_list[tmp] : {num_list[tmp]}')"""
        # 왼쪽으로 회전
        if num_list[-tmp] == pick_nums[0]:
            num_list.rotate(tmp)
            break
        # 오른쪽으로 회전
        if num_list[tmp] == pick_nums[0]:
            num_list.rotate(-tmp)
            break
    if num_list[0] == pick_nums[0]:
        num_list.popleft()
        pick_nums.popleft()
    cnt += tmp
print(cnt)

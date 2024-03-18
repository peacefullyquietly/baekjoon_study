# 회의실 배정
'''
반례
2
1 1
2 2

output : 0
answer : 2

'''
import sys

# 입력 받기
N = int(sys.stdin.readline())
time = []
for _ in range(N):
    start, end = map(int, sys.stdin.readline().split())
    time.append((start, end))

# 끝나는 시간을 기준으로 정렬하기
time.sort(key=lambda x: x[1])

# 겹치지 않는 강의의 최대 개수 구하기
count = 1  # 첫 번째 강의는 무조건 포함하므로 초기값을 1로 설정
end_time = time[0][1]  # 첫 번째 강의의 끝나는 시간으로 초기화
for i in range(1, N):
    if time[i][0] >= end_time:  # 현재 강의의 시작 시간이 이전 강의의 끝나는 시간보다 뒤에 있으면
        count += 1  # 강의 개수를 증가시키고
        end_time = time[i][1]  # 현재 강의의 끝나는 시간으로 업데이트

# 결과 출력
print(count)

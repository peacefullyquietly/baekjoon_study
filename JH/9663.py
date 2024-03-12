# N-queen
'''
1. A행부터 총 N번 반복함 (A1~An)
ex)
A1에 queen을 둔다고 가정했을 때, B,C,D... 줄에 queen을 놓을 수 있는 경우의 수를 count
'''
import sys

N = int(sys.stdin.readline().rstrip())

# chessboard = [[True] * (N+1) for _ in range(N+1)
isused1 = [0]*N
isused2 = [0] * (N*2-1)        # left_bottom -> top_right
isused3 = [0] * (N*2-1)          # top_right -> left_bottom

count = 0


def n_queen(cur):
    global count

    # cur = x, 행 증가
    if cur == N:
        count += 1
        return

    # i == 열 증가
    for i in range(N):
        # print("현재 i 값: ", i)
        if isused1[i] != 0 or isused2[i+cur] != 0 or isused3[cur-i+N-1] != 0:
            continue

        isused1[i] = 1
        isused2[i + cur] = 1
        isused3[cur - i + N - 1] = 1
        n_queen(cur+1)
        isused1[i] = 0
        isused2[i + cur] = 0
        isused3[cur - i + N - 1] = 0


n_queen(0)
print(count)

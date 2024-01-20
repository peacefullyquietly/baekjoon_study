# 정수 삼각형

# Bottom-up
import sys

n = int(sys.stdin.readline().rstrip())

number = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]


def find_max_path_sum(triangle):
    for i in range(1, n):
        for j in range(len(triangle[i])):

            if j == 0:
                triangle[i][j] += triangle[i-1][j]
            elif j == i:
                triangle[i][j] += triangle[i-1][j-1]
            else:
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j])

    return max(triangle[-1])


result = find_max_path_sum(number)
print(result)

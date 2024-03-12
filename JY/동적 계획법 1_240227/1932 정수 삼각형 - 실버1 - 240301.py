import sys
input = sys.stdin.readline


def find_max(N):
    answers[0][0] = triangle[0][0]
    if N == 1:
        return max(answers[0])
    answers[1][0] = answers[0][0] + triangle[1][0]
    answers[1][1] = answers[0][0] + triangle[1][1]
    if N == 2:
        return max(answers[1])
    for i in range(2, N):
        answers[i][0] = answers[i-1][0] + triangle[i][0]
        for j in range(1, len(answers[i])-1):
            answers[i][j] = max(answers[i-1][j-1],
                                answers[i-1][j]) + triangle[i][j]
        answers[i][-1] = answers[i-1][-1] + triangle[i][-1]
    return max(answers[-1])


N = int(input())

triangle = []
answers = [[0 for i in range(j+1)]for j in range(N)]
for i in range(0, N):
    line = list(map(int, input().split()))
    triangle.append(line)

print(find_max(N))

# print(triangle)
# print(answers)

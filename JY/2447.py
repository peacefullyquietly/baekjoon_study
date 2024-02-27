import sys

input = sys.stdin.readline
# N은 3의 거듭제곱


def draw_stars(N):
    if N == 1:
        return "*"
    line = []
    left = draw_stars(N // 3)
    center = " " * (N // 3)
    for i in left:
        line.append(i*3)
    for i in left:
        line.append(i+center+i)
    for i in left:
        line.append(i*3)
    return line


N = int(input())
print("\n".join(draw_stars(N)))

#
# https://lucian-blog.tistory.com/57

# 재귀적인 방법으로 n을 1까지 도달하게 한다음 "*"을 리턴
# N = 3일 때 left = draw_stars(1)이되어 밑의 반복문 실행 시작 => left = ["*"]
# line = ["***", "* *", "***"]이 됨
# N = 9일 때 left = draw_stars(3) => left = ["***", "* *", "***"]
# line = ["*********", "* ** ** *", "*********"]이 됨
# (재귀의 결과인 left의 값에따라 for i in left 이런식으로 반복문돌리는게 신기하다)

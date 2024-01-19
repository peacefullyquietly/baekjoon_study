import sys
input = sys.stdin.readline

triangle = list(map(int, input().split()))
triangle.sort()
if triangle[0] + triangle[1] > triangle[2]:
    print(sum(triangle))
else:
    print((triangle[0] + triangle[1]) * 2 - 1)

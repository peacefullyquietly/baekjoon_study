import sys
input = sys.stdin.readline
N, k = list(map(int, input().split()))
score = list(map(int, input().split()))
score.sort()
print(score[-k])

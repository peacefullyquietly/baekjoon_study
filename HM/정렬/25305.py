N, k = map(int, input().split())
score = sorted(list(map(int, input().split()))) 

print(score[-k])


import sys
input = sys.stdin.readline

N = int(input())
X_list = list(map(int, input().split()))

# 1트 -> 시간초과
"""sorted_list = sorted(list(set(X_list)))
for i in range(N):
    for j in range(N):
        if X_list[i] == sorted_list[j]:
            print(j, end=" ")
            break
"""

# 2트
sorted_list = sorted(list(set(X_list)))
dict_list = dict(zip(sorted_list, list(range(len(sorted_list)))))

for i in X_list:
    print(dict_list[i], end=" ")

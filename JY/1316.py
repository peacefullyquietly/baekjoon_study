import sys
input = sys.stdin.readline
n = int(input())
# kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
# aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

# a b c 연달아 넣고 b가 또 나오면 다른 그룹 단어
# 인덱스 뽑기

result = 0
flag = True
for i in range(n):
    tmp = input().rstrip()
    set_tmp = set(tmp)
    for j in set_tmp:
        idx_list = []
        for k in range(len(tmp)):
            if j == tmp[k]:
                idx_list.append(k)
            for l in range(-1, -(len(idx_list)), -1):
                if len(idx_list) > 1 and idx_list[l] - idx_list[l-1] > 1:
                    flag = False
    if flag == True:
        result += 1
    else:
        flag = True

print(result)

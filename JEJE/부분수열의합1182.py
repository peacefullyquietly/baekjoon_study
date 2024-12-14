import sys

input = sys.stdin.readline

def make_comb(arr, comb,s):
    cnt = 0
    for i in arr:
        for j in list(comb):
            num = i+j
            comb.append(num)
            if num == s:
                cnt += 1
    return cnt

n, s = map(int, input().split())
comb = [0]
arr = list(map(int, input().split()))
cnt = make_comb(arr, comb, s)
print(cnt)

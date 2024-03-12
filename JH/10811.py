# 바구니 뒤집기

import sys
N, M = map(int, sys.stdin.readline().rstrip().split())

basket = [i for i in range(N+1)]                # 포인트 ~

for i in range(M):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    basket[b:a-1:-1] = basket[a:b+1:]           # 포인트 ~~
    # print("basket:",basket)

print(*basket[1:])

# a = [1,2,3,4,5]
# a[4:0:-1] = a[1::]
# print(a)

# 첫 번째 숫자가 두 번째 숫자의 약수이다.
# 첫 번째 숫자가 두 번째 숫자의 배수이다.
# 첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다.

import sys

flag = True
while flag == True:
    input = sys.stdin.readline
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        flag = False
        break
    elif b % a == 0:
        print("factor")
    elif a % b == 0:
        print("multiple")
    else:
        print("neither")

import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
for i in range(T):
    error_occured = False
    p = input().rstrip()
    n = int(input())
    # x = input().rstrip().replace('[', '').replace(']', '').split(',')
    x = input().lstrip('[').rstrip(']\n').split(',')
    if n != 0:
        x = deque(map(int, x))
    if x[0] == '':
        x = []
    """
    1. **함수 R은 배열에 있는 수의 순서를 뒤집는 함수**
    2. **함수 D는 첫 번째 수를 버리는 함수**
    - 배열이 비어있는데 D를 사용한 경우에는 에러가 발생
    """
    reversed_flag = False
    for i in p:
        if i == 'D':
            if len(x) > 0:
                if reversed_flag == False:
                    x.popleft()
                else:
                    x.pop()
            else:
                print("error")
                break
        else:
            reversed_flag = not reversed_flag
    else:
        if reversed_flag:
            x.reverse()
        print("[", end="")
        print(*x, sep=",", end="")
        print("]")

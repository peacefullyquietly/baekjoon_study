import sys
input = sys.stdin.readline

# 유클리드 호제법으로 최대공약수 구하기
# 두 양의 정수 a, b (a > b)에 대하여
# a, b의 최대공약수는 b, r의 최대공약수와 같다.
# 유클리드 반복문 방식


def Euclidean(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


"""유클리드 재귀문 방식
def Euclidean(a, b):    
    r = b % a    
    if r == 0:        
        return a    
    return Euclidean(r, a)
출처: https://baby-dev.tistory.com/97
"""

T = int(input())
for i in range(T):
    A, B = map(int, input().split())
    print(A*B//Euclidean(A, B))

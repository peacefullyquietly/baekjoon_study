import sys

input = sys.stdin.readline
T = int(input())
for i in range(T):
    C = int(input())
    # C의 단위는 센트(1달러 = 100센트) (1<=C<=500)
    # 쿼터 / 다임 / 니켈/ 페니 개수 출력
    if C // 25 >= 0:
        quarter = int(C//25)
        C -= 25 * quarter
        print(quarter, end=" ")
    if C // 10 >= 0:
        dime = int(C//10)
        C -= 10 * (dime)
        print(dime, end=" ")
    if C // 5 >= 0:
        nickel = int(C//5)
        C -= 5 * nickel
        print(nickel, end=" ")
    if C // 1 >= 0:
        penny = int(C//1)
        C -= 1 * (penny)
        print(penny, end=" ")
    print()

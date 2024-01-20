import sys
input = sys.stdin.readline

flag = True
while flag:
    a, b, c = list(map(int, input().split()))
    triangle = [a, b, c]
    max_edge = max(triangle)
    triangle.remove(max_edge)
    if a == 0 and b == 0 and c == 0:
        flag = False
        break
    elif not triangle[0] + triangle[1] > max_edge:
        print("Invalid")
    elif a == b == c:
        print("Equilateral")
    elif (a == b or a == c or b == c):
        print("Isosceles")
    elif (a != b and b != c and a != c):
        print("Scalene")

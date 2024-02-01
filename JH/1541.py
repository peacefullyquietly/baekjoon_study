# 잃어버린 괄호
import sys

list = []
list.append(sys.stdin.readline().rstrip().split('-'))

plus = []
for i in range(len(list[0])):
    a = list[0][i].split('+')
    point = 0
    for j in a:
        point += int(j)

    plus.append(point)

result = plus[0]
for k in plus[1:]:
    result -= k

print(result)

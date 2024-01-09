# 칸토어 집합
import sys


def cantor_set(list, start, seperator):
    global cantor
    for i in range(seperator):
        list[start] = " "
        start += 1


while True:
    try:
        n = int(sys.stdin.readline().rstrip())
        cantor = ["-"] * (3**n)
        seperator = (3**n) // 3
        tmp = seperator

        for i in range(n):
            cnt, i = 0, 1
            for a in range(0, 3**n, seperator):
                if cnt == i:
                    cantor_set(cantor, a, seperator)
                    i += 3
                cnt += 1
            else:
                seperator //= 3

        for i in cantor:
            print(i, end="")
        print()
    except:
        break

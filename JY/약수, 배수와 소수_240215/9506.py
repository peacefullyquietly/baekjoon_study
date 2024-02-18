import sys
input = sys.stdin.readline


def is_perfect(n):
    divisor = []
    for i in range(1, n):
        if n % i == 0:
            divisor.append(i)
    if n == sum(divisor):
        print(f"{n} =", end=" ")
        print(*divisor, sep=" + ", end="\n")
        # 한 줄로 작성하는법 - gpt
        # print(f"{n} = {' + '.join(map(str, divisor))}")
    else:
        print(n, "is NOT perfect.")


while True:
    n = int(input())
    if n == -1:
        break
    else:
        is_perfect(n)

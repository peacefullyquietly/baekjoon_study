def pac(n, p = 1):
    if n <= 0:
        return p
    pac(n-1, n*(n-1))

answer = pac(int(input()))
print(answer)
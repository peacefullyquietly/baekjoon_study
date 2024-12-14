import sys

N = int(sys.stdin.readline()[:-1])
i = 2
while N != 1:
    if N%i == 0:
        N //= i 
        sys.stdout.write(f"{i}\n")
    else:
        i += 1
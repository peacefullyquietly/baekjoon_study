import sys
correct = []
K = int(sys.stdin.readline()[:-1])
for _ in range(K):
    N = int(sys.stdin.readline()[:-1])
    if N != 0:
        correct.append(N)
    else:
        correct.pop()
sys.stdout.write(f'{sum(correct)}\n')
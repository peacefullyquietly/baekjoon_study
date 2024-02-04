import sys
input = sys.stdin.readline
N = int(input())

log = set()
for i in range(N):
    tmp = list(map(str, input().rstrip().split()))
    if tmp[1] == "enter":
        log.add(tmp[0])
    elif tmp[1] == "leave":
        log.remove(tmp[0])

log = list(log)
log.sort(reverse=True)
print(*log, sep="\n")

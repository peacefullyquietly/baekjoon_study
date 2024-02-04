# 셀프 넘버

'''첫번째 방법'''
n = 1
setA = set(i for i in range(1, 10001))
setB = set()

cnt = 1
while n < 10000:
    if n < 10:
        cnt = n+n

    elif 10 <= n < 100:     # n이 두자리수 일 때
        tmp = str(n)
        cnt = int(tmp) + int(tmp[0]) + int(tmp[1])

    elif 100 <= n < 1000:          # n이 세자리 수 일 때
        tmp = str(n)
        cnt = int(tmp) + int(tmp[0]) + int(tmp[1]) + int(tmp[2])

    elif 1000 <= n < 10000:         # n이 네자리 수 일 때
        tmp = str(n)
        cnt = int(tmp) + int(tmp[0]) + int(tmp[1]) + int(tmp[2]) + int(tmp[3])

    setB.add(cnt)
    n += 1

result = list(setA - setB)
result.sort()
print(*result, sep="\n")


''' 두번째 방법'''

setA = set(range(1, 10001))
setB = set()

for i in list(setA):
    for j in str(i):
        i += int(j)
    setB.add(i)

self_num = list(setA - setB)
self_num.sort()
print(*self_num, sep="\n")

# 알고리즘 - 병합 정렬 1

import sys


def merge_sort(A, p, r):
    if p < r:
        q = (p+r) // 2      # q는 p,r의 중간지점

        merge_sort(A, p, q)     # 전반부 정렬
        merge_sort(A, q+1, r)   # 후반부 정렬
        merge(A, p, q, r)       # 병합


def merge(A, p, q, r):
    global cnt
    global result
    global tmp

    i, j, t = p, q+1, 0
    while i <= q and j <= r:
        if A[i] <= A[j]:
            tmp[t] = A[i]
            t += 1
            i += 1
        else:
            tmp[t] = A[j]
            t += 1
            j += 1

    while i <= q:           # 왼쪽 배열 부분이 남은 경우
        tmp[t] = A[i]
        t += 1
        i += 1

    while j <= r:           # 오른쪽 배열 부분이 남은 경우
        tmp[t] = A[j]
        t += 1
        j += 1

    i, t = p, 0

    global x
    while i <= r:           # 결과를 배열 A에 저장
        cnt += 1
        A[i] = tmp[t]

        if cnt == x:
            result = A[i]
            print(A[i])
            sys.exit()          # 코드 종료

        i += 1
        t += 1


global x
cnt = 0
result = 0

n, x = map(int, sys.stdin.readline().rstrip().split())

arr = list(map(int, sys.stdin.readline().rstrip().split()))
tmp = [0]*n
merge_sort(arr, 0, n-1)

if result == False:
    print(-1)

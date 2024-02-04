import sys
input = sys.stdin.readline


def merge_sort(A, p, r):  # A[p..r]을 오름차순 정렬한다.
    if (p < r):
        q = (p + r) // 2       # q는 p, r의 중간 지점
        merge_sort(A, p, q)      # 전반부 정렬
        merge_sort(A, q + 1, r)  # 후반부 정렬
        merge(A, p, q, r)        # 병합
# A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
# A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.

    """
    A = 리스트
    p = left
    q = mid
    r = right
    """


def merge(A, p, q, r):
    global tmp
    global ans
    i = p       # 배열 C(정렬될 리스트)의 인덱스
    j = q + 1   # 배열 B의 인덱스
    t = 0       # 배열 A의 인덱스
    while (i <= q and j <= r):
        if (A[i] <= A[j]):
            tmp[t] = A[i]
            t, i = t + 1, i + 1
            # tmp[t] <- A[i]; t++; i++;
        else:
            tmp[t] = A[j]
            t, j = t + 1, j + 1
            # tmp[t] <- A[j]; t++; j++;
    while (i <= q):  # 왼쪽 배열 부분이 남은 경우
        # (한쪽에 남아있는 레코드의 일괄 복사 -> 슬라이싱도 OK)
        tmp[t] = A[i]
        t, i = t + 1, i + 1
    while (j <= r):  # 오른쪽 배열 부분이 남은 경우
        # (한쪽에 남아있는 레코드의 일괄 복사 -> 슬라이싱도 OK)
        tmp[t] = A[j]
        t, j = t + 1, j + 1
    i = p
    t = 0
    while (i <= r):  # 결과를 A[p..r]에 저장
        # 정렬된 tmp를 원래 배열 A에 복사함
        A[i] = tmp[t]
        # 문제에 따른 저장되는 수 출력 위해 코드 추가함
        ans.append(A[i])
        t, i = t + 1, i + 1


N, K = list(map(int, input().split()))
arr = list(map(int, input().split()))
ans = []

# 배열 A에 K 번째 저장 되는 수를 출력한다.
# 저장 횟수가 K 보다 작으면 -1을 출력한다.
tmp = [0 for i in range(N)]
merge_sort(arr, 0, len(arr)-1)
# print(ans)
if len(ans) < K:
    print(-1)
else:
    print(ans[K-1])

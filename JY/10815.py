import sys
input = sys.stdin.readline

N = (int(input()))
card_N = list(map(int, input().split()))

M = (int(input()))
card_M = list(map(int, input().split()))


def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None


card_N.sort()

for i in range(M):
    if binary_search(card_N, card_M[i], 0, N-1) is not None:
        print("1", end=" ")
    else:
        print("0", end=" ")

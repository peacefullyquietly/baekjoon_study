# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
import sys
N =int(sys.stdin.readline()[:-1])
un_sorted = []
for _ in range(N):
    un_sorted.append(int(sys.stdin.readline()[:-1]))

def partition(arr, start, end):
    pivot = arr[start]
    left = start + 1
    right = end
    done = False
    while not done:
        while left <= right and arr[left] <= pivot:
            left += 1
        while left <= right and pivot <= arr[right]:
            right -= 1
        if right < left:
            done = True
        else:
            arr[left], arr[right] = arr[right], arr[left]
    arr[start], arr[right] = arr[right], arr[start]
    return right


def quick(arr, start, end):
    if start < end:
        pivot = partition(arr, start, end)
        quick(arr, start, pivot - 1)
        quick(arr, pivot + 1, end)
    return arr


for i in quick(un_sorted, 0, len(un_sorted)-1):
    sys.stdout.write(str(i)+'\n')
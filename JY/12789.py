# 12789 도키도키 간식드리미
import sys
from collections import deque

wait_stack = deque()
snack_stack = deque()

input = sys.stdin.readline
N = int(input())
student = deque(map(int, input().split()))
# print(student)
Flag = True

number = 1
while number < N:
    if len(student) > 0 and student[0] == number:
        snack_stack.append(student.popleft())
        number += 1
    elif len(student) > 0 and student[0] != number:
        if len(wait_stack) > 0 and wait_stack[-1] == number:
            snack_stack.append(wait_stack.pop())
            number += 1
        else:
            wait_stack.append(student[0])
            student.popleft()
    elif len(wait_stack) > 0 and wait_stack[-1] == number:
        snack_stack.append(wait_stack.pop())
        number += 1
    else:
        Flag = False
        break

    # print(student, wait_stack, snack_stack)
if Flag:
    print("Nice")
else:
    print("Sad")

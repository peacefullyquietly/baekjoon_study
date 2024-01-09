# 재귀의 귀재
# 재귀 공부하자

import sys


def recursion(s, l, r):
    global count
    if l >= r:
        return 1
    elif s[l] != s[r]:
        return 0
    else:
        count += 1
        return recursion(s, l+1, r-1)


def isPalindrome(s):
    global count
    count = 1
    return recursion(s, 0, len(s)-1)


def main():
    n = int(sys.stdin.readline().rstrip())
    for i in range(n):
        string = sys.stdin.readline().rstrip()
        result = isPalindrome(string)
        print(result, count)


if __name__ == "__main__":
    main()

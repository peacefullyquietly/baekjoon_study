# 알파벳 개수
import sys

alphabet_count = [0] * 26

word = sys.stdin.readline().rstrip()

for char in word:
    if 'a' <= char <= 'z':
        alphabet_count[ord(char) - ord('a')] += 1

print(*alphabet_count)

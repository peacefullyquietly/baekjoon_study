import sys

input = sys.stdin.readline
N, M = map(int, input().split())

wordbook = dict()
for i in range(N):
    word = input().rstrip()
    if len(word) >= M:
        if word not in wordbook:
            wordbook.update({word: 1})
        else:
            freq = wordbook.get(word)
            wordbook.update({word: freq+1})
wordbook = sorted(wordbook.items(), key=lambda x: (-x[1], -len(x[0]), x[0]))
# -x[1] = 자주 나오는 단어일수록 앞에 배치한다.
# -len(x[0]) = 해당 단어의 길이가 길수록 앞에 배치한다.
# x[0] = 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다.

for i in wordbook:
    print(i[0])

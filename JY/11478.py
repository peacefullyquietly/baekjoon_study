import sys
input = sys.stdin.readline

S = input().rstrip()

str_list = set()

for i in range(0, len(S)):
    for j in range(i, len(S)+1):
        str_list.add(str(S[i:j]))

str_list.remove('')
print(len(str_list))

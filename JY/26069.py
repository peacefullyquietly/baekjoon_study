import sys
from collections import defaultdict
input = sys.stdin.readline

dance = defaultdict(bool)
dance['ChongChong'] = True
ans = 1

for i in range(int(input())):
    a, b = map(str, input().split())
    if dance[a]:
        if not dance[b]:
            dance[b] = True
            ans += 1
    elif dance[b]:
        dance[a] = True
        ans += 1

print(ans)

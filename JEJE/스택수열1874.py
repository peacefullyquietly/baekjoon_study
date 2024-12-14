import sys

n = int(sys.stdin.readline()[:-1])
st = []
ans = []
cur = 1

for _ in range(n):
    num = int(sys.stdin.readline()[:-1])
    while cur <= num:
        st.append(cur)
        cur += 1
        ans.append('+')
    if st[-1] == num:
        st.pop()
        ans.append('-')
    else:
        ans.clear()
        ans.append("NO")
        break
    
for i in ans:
    print(i)
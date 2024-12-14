import datetime

start = datetime.datetime.strptime(input(), '%Y.%m.%d')
end = datetime.datetime.strptime(input(), '%Y.%m.%d')
    
delta = (end - start).days

ans = 0
for i in range(delta+1):
    current = start + datetime.timedelta(days=i)
    if current.weekday() == 4:
        ans += current.month + current.day

print(ans, ans*2, sep=' ')
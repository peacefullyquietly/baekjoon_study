import sys
N = int(sys.stdin.readline()[:-1])
S = [i*0 for i in range(20)]
for _ in range(N):
    order = sys.stdin.readline()[:-1]
    if order == 'all':
        S = [i+1 for i in range(20)]
    elif order == 'empty':
        S = [i*0 for i in range(20)]
    else:
        order = order.split()
        order[1] = int(order[1])
        if order[0] == 'add' and S[order[1]-1] != order[1]:
            S[order[1]-1] = order[1]
        elif order[0] == 'remove'and S[order[1]-1] == order[1]:
            S[order[1]-1] = 0
        elif order[0] == 'check':
            if S[order[1]-1] == order[1]:
                print(1)
            elif S[order[1]-1] != order[1]:
                print(0)
        elif order[0] == 'toggle':
            if S[order[1]-1] == order[1]:
                S[order[1]-1] = 0
            else:
                S[order[1]-1] = order[1]
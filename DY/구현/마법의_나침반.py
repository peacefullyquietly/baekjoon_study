'''
32372
1: N(맵 크기) M(나침반 개수)
1+i: X_i Y_i K_i(방향)

보물위치 출력하기~

x_min, x_max, y_min, y_max

1: x_max = min(x-1, x_max), y_min = y_max = y
2: x_max = min(x-1, x_max), y_min = max(y+1, y_min)
3: x_min = x_max = x, y_min = max(y+1, y_min)
4: x_min = max(x+1, x_min), y_min = max(y+1, y_min)
...

x좌표가 작고: 1, 2, 8
x좌표가 크고: 4, 5, 6
x좌표가 같고: 3, 7

y좌표가 작고: 6, 7, 8
y좌표가 크고: 2, 3, 4
y좌표가 같고: 1, 5
'''

def solve(n, m):
    x_min, x_max, y_min, y_max = 1, n-1, 1, n-1
    for _ in range(m):
        x, y, k = map(int, input().split())
        if k == 1 or k == 2 or k == 8:
            x_max = min(x-1, x_max)
        elif k == 4 or k == 5 or k == 6:
            x_min = max(x+1, x_min)
        else :
            x_min = x_max = x
        if k == 6 or k == 7 or k == 8:
            y_max = min(y-1, y_max)
        elif k == 2 or k == 3 or k == 4:
            y_min = max(y+1, y_min)
        else:
            y_min = y_max = y
    print(x_min, y_min)

if __name__ == '__main__':
    n, m = map(int, input().split())
    solve(n, m)
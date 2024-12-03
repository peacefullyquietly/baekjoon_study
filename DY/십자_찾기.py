'''
32715
1s 1024MB

1: N M (모눈종이의 크기 NM: 1~2500)
2: K (십자의 크기)
3+i: 모눈종이 한 행씩 출력. 색칠되어 있으면 1
=> 크기가 K인 십자의 개수
---
모눈종이 배열을 m이라고 할 때,

k~n-k행을 순회하며(x)
m[x][i]가
- 0이면 m[x][i] = 0
- 1이면 m[x][i] = m[x][i-1]+1을 하고,

누적 acc를 두고
k~m-k열을 순회하며(x)
m[i][x]가
- 0이면 acc=0
- 그 이상이면 
    1. acc += 1을 하고,
    2. acc가 k*2+1이상이면 m[i-k][x+k]도 k*2+1이상인지 확인  true=> 십자가 수 + 1
'''
def solve(n, m, k, board):
    # 행 순회
    for x in range(k+1, n-k+1):
        for i in range(1, m+1):
            if board[x][i] == 1:
                board[x][i] = board[x][i-1] + 1

    result = 0
    acc = 0
    for x in range(k+1, m-k+1):
        for i in range(1, n+1):
            if board[i][x] == 0:
                acc = 0
            else:
                acc += 1
                if acc >= k*2+1 and board[i-k][x+k] >= k*2+1:
                    result += 1
    
    print(result)

if __name__ == '__main__':
    n, m = map(int, input().split())
    k = int(input())
    board = [[0 for _ in range(m+1)]]
    for _ in range(n):
        board.append([0]+list(map(int, input().split())))
    solve(n, m, k, board)
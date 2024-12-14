answer = 0
tc = int(input()) #테스트 케이스 입력 받음
arr = [[]for i in range(tc+1)] # [[],[],[]] 만들기

for i in range(tc): #색깔별로 분류
    x, color = list(map(int, input().split()))
    arr[color].append(x)

for i in range(len(arr)): #합 구하기 시작
    if len(arr[i]) > 1: #만약 같은 색깔 상에서 좌표가 1개보다 많으면
        arr[i].sort() #정렬하고
        
        for j in range(len(arr[i])): #이제 좌표 하나씩 읽기 시작함
            if j==0: 
                answer += abs(arr[i][j]-arr[i][j+1]) #맨 처음 좌표
            elif j==len(arr[i])-1: 
                answer += abs(arr[i][j]-arr[i][j-1]) #맨 마지막 좌표
            else:
                answer += min(abs(arr[i][j]-arr[i][j+1]), abs(arr[i][j]-arr[i][j-1])) #사이에 있는 좌표들

#min(a,b): a와 b중 최솟값을 알려준다
#abs(): 절댓값을 리턴함(알려줌)

#a+=b: a = a+b
#추가로 a-=b: a = a-b
#*=, /=도 있음

print(answer) #정답 출력

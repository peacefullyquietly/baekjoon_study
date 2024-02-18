N,M = map(int, input().split())
matrix=[]


for i in range(N):
    # matrix.append(list(input()))
    # 위의 코드의 문제점
    # 리스트의 원소를 입력받을 때 
    # list.append(list(input()))와 같이 코드를 작성하면 
    # 잘못된 동작을 일으킵니다. 
    # 이 코드는 입력된 문자열을 문자 하나씩 리스트에 추가하는 대신, 
    # 문자열 자체를 리스트의 원소로 추가합니다.
    row = list(input())
    matrix.append(row)
    
    for i in range(N-7):
        for j in range(M-7):
            
        
    

print(matrix)
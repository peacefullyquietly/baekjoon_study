N,B=map(int,input().split())
number="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

result=""
while N: # N이 0이 될 때까지
    result+=str(number[N%B])
    N//=B

print(result[::-1])

    

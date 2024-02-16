X= int(input()) # 영수증에 적힌 총 금액
N = int(input()) # 구매한 물건의 종류의 수

sum=0
for i in range(N):
    a,b= input().split() #물건 가격 a, 개수 b
    a= int(a) 
    b= int(b)
    sum+= a*b
if X==sum:
    print("Yes")
else:
    print("No")


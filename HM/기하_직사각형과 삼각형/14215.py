arr = list(map(int, input().split()))

a, b, c= sorted(arr)



if a==b==c:
    print(a+b+c)

else:
    if a+b<=c:
       print(2*a+2*b-1) 
    else:print(a+b+c) 
    # 예시: 3 3 4
        

t = int(input())

for i in range(1, t+1):
    n1,n2 = map(int,input().split())
  
    sum = n1+n2
    print(f"Case #{i}: {n1} + {n2} = {sum}")

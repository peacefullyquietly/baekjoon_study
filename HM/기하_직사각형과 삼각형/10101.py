A=int(input())
B=int(input())
C=int(input())

if A+B+C!=180:
    print("Error")
else:
    if A!=B and A!=C and B!=C:
        print("Scalene")
    elif A==B and A==C:
        print("Equilateral")
    else:print("Isosceles")
    
        
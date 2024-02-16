
# while True:
#     a, b, c = map(int, input().split())
#     if a==0 and b==0 and c==0:
#        print("Invalid")
#        break
#     if a!=b and a!=c and b!=c:
#         print("Scalene")
        
#     elif a==c and a==b:
#        print("Equilateral")
   
        
#     elif a==b or a==c:
#         print("Isosceles")
        

while True :
  a, b, c = map(int, input().split())
  if a == b == c == 0 :
    break
  if sum((a, b, c)) - max((a, b, c)) <= max((a, b, c)) :
    print("Invalid")
  elif a == b == c :
    print('Equilateral')
  elif a == b or b == c or a == c :
    print("Isosceles")
  else :
    print("Scalene")  

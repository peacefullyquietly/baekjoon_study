N = int(input())
list = []
for i in range(N):
    age, name = input().split()
    age=int(age)
    list.append([age, name])

list.sort(key=lambda x: x[0])   
# list.sort() 
# ************

for i in list:
    print(" ".join(str(j) for j in i ))
    
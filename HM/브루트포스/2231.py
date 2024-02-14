# N = int(input())
# list =[]
# for i in range(10):
#     for j in range(10):
#         for k in range(10):
#             if i*100+j*10+k+i+j+k==N:
#                 list.append(i*100+j*10+k)
# print(min(list))

                
N = int(input())
length=len(str(N))

sum =0
for i in range(length):
    for j in range(10):
        sum+=j **(length-i)+j  
      
print(sum)
       
       
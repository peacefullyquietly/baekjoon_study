# N = int(input())
# list =[]
# for i in range(10):
#     for j in range(10):
#         for k in range(10):
#             if i*100+j*10+k+i+j+k==N:
#                 list.append(i*100+j*10+k)
# print(min(list))

                
# N = int(input())
# length=len(str(N))

# sum =0
# for i in range(length):
#     for j in range(10):
#         print(j*10**(length-i-1))
#         sum+=j*10**(length-i-1)+j  
      
# print(sum)
       

N = int(input())
total=0
for i in range(1, N):
    nums =list(str(i))
    num = list(map(int,nums))
    # print(num)
    # print(sum(num))
    total=sum(num)+i

    if total==N:
        print(i)
        break
else:
    print(0)        
   
    # if sum(num)+i==N:
    #     print(i)
# print(sum([1,3,4]))
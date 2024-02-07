o_list= [1,1,2,2,2,8]
u_list= list(map(int, input().split()))
for i in range(len(o_list)):
    print(o_list[i]-u_list[i], end=" ")


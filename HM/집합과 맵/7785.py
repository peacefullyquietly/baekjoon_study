# N = int(input())
# enter=set()
# leave=set()
# for  i in range(N):
#     name,status =input().split() 
#     if status=='enter':
#         enter.add(name)
#     else:leave.add(name)
    
# enter = enter-leave
# enter=sorted(enter, reverse=True)

# for i in enter:
#     print(i)

N = int(input())
enter=set()

for  i in range(N):
    name,status =input().split() 
    if status=='enter':
        enter.add(name)
    else:enter.remove(name)
    

enter=sorted(enter, reverse=True)

for i in enter:
    print(i)
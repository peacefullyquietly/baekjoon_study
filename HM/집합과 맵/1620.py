# import sys

# N , M =map(int, sys.stdin.readline().split())
# dic={}
# for i in range(1,N+1):
#     name = sys.stdin.readline().rstrip()
    
#     dic[i]=name
    
# for i in range(M):
#     quest= sys.stdin.readline().rstrip()
#     if quest.isdigit(): #포켓몬의 번호 주어졌을때
#         print(dic[int(quest)])
#     else: # 포켓몬의 이름이 주어졌을때
#         for j in dic.items():
#             if j[1]==quest:
#                 print(j[0])
                
import sys

N , M =map(int, sys.stdin.readline().split())
dic={}
for i in range(1,N+1):
    name = sys.stdin.readline().rstrip()
    
    dic[i]=name
    dic[name]=i
    
for i in range(M):
    quest= sys.stdin.readline().rstrip()
    if quest.isdigit(): #포켓몬의 번호 주어졌을때
        print(dic[int(quest)])
    else: # 포켓몬의 이름이 주어졌을때
              print(dic[quest])

                



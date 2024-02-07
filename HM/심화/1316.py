n = int(input())
count=0
for i in range(n):
    
    word= input()
    list=[] 
   
    c= word[0]
    list.append(c)
    for i in range(len(word)):
        if c!=word[i]:
            c=word[i]
            list.append(c)
    if len(set(word))==len(list):
        count+=1

print(count)

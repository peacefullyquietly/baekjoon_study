numbers= ['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']
count=0
s= input()
for i in s:
    for j in numbers:
        if i in j:
            count+=numbers.index(j)+3
            
print(count)
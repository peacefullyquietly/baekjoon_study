c= ['c=', 'c-', 'dz=', 'd-','lj','nj', 's=', 'z=']
word= input()
count=0
for i in c:
    word = word.replace(i,'*')
print(len(word))

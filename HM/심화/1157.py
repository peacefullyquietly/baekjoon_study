word =input().upper()
word_list= list(set(word))
count_list=[]
for i in word_list:
   
    count_list.append(word.count(i))
max = max(count_list)
if  count_list.count(max)>=2:
    print("?")
else: print(word_list[count_list.index(max)])

# max>=2 and
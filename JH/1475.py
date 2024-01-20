# 방번호
import sys
room_number = list(sys.stdin.readline().rstrip())

dic = {"0": 0, "1": 0, "2": 0, "3": 0,
       "4": 0, "5": 0, "6": 0, "7": 0, "8": 0, }
count = 0
for i in room_number:
    a = i
    if a == "6" or a == "9":
        count += 1
        if count == 2:
            dic["6"] += 1
            count = 0
    else:
        dic[i] += 1
if count > 0:
    dic["6"] += 1

dic = dict(sorted(dic.items(), key=lambda k: (k[1]), reverse=True))
result = list(dic.keys())

print(dic[result[0]])

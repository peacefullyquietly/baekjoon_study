# https://programmers.co.kr/learn/courses/30/lessons/49993
def solution(skill, skill_trees):
    answer = 0
    dic = {}
    alph = ["Q","W","E","R","T","Y","U",'I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M']
    for i in alph:
        dic[i] = 0
    for i, word in enumerate(list(skill), start = 1):
        dic[word] = i
    for i in skill_trees:
        count = 1
        for j in list(i):
            if dic[j] > count:
                count = 0
                break
            elif dic[j] == count:
                count +=1
            elif count == len(skill):
                break
        if count > 0: answer+=1
    return answer
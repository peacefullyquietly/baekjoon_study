# s1 = input()
# s2 = input()
# s3 = input()
# s4 = input()
# s5 = input()

# s = list(zip(s1, s2, s3, s4, s5))
# for i in range(5):
#     for j in range(5):
#         print(s[i][j],end="")

# zip( )쓰는 거 아님

words = []
length = []
for i in range(5):
    word = input()
    words.append(word)
    length.append(len(word))
for i in range(max(length)): # w가장 긴 문자열 길이만큼 반복하면서 글자가 있는지 확인하는 반복문
    for j in range(5):
        if i < length[j]: # 글자수가 있는지 확인하고 있는 인덱스 숫자보다
            # word의 길이(length[j])가 길면 그 인덱스에 글자가 있다는 뜻!
            print(words[j][i], end="")


word = input()
temp = word[::-1]
if word==temp:
    print(1)
else :print(0)


word = input()
print(1 if word==word[::-1] else 0)

S = input()
alphabet = list(range(ord('a'), ord('z')+1))

for i in alphabet:
    print(S.find(chr(i)),end=" ")

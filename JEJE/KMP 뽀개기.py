# None
#와! 파이썬 오랜만이야
#난 그렇게 원서 접수하고 1차합을 기다리고 있어!!
#그러면 면접 대비를 위해 다같이 KMP를 공부해볼까?

# list = [0]*5
# print(list)
# [0, 0, 0, 0, 0]
#https://devbull.xyz/python-kmp-algorijeumeuro-munjayeol-cajgi/

def LPS(txt):
    i = 0
    j = 1
    lps = [0]*(len(txt)+1)
    while i < len(txt):
        if txt[i] == txt [j]:
        i += 1
        lps[j] = i
        j += 1
        else:
            if i != 0:
                j = 
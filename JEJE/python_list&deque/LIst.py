import time
# from collections import deque

result = []

def check(func):
    def wrapper():
        for _ in range (20):
            start = time.time()
            func()
            result.append(time.time() - start)
    return wrapper

@check
def test():
    l = []
    for i in range(10000000):
        l.append(i)
    while l:
        l.pop()

def getResult():
    test()
    print(sum(result)/len(result))

getResult()
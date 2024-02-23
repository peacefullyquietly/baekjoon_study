import sys

input = sys.stdin.readline

# 골드바흐의 추측: 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다.

# 에라토스테네스의 체 이용하여 소수 구하기
N = 1000001
primeList = [True] * N
primeList[0] = False
primeList[1] = False
maxNum = int(N ** 0.5)
for i in range(2, maxNum + 1):
    if primeList[i] == True:
        for j in range(i+i, N, i):
            primeList[j] = False

T = int(input())
# 각각의 테스트 케이스마다 골드바흐 파티션의 수를 출력한다.
for _ in range(T):
    # print(primeNums)
    n = int(input())
    ans = 0
    for i in range(2, n//2+1):
        # 시간 초과 나서 결국 인터넷 도움받음.
        # 난 맨날 이중포문으로 할생각만 했는데 좀 천재같다
        if primeList[i] and primeList[n-i]:
            ans += 1
        """
        여기서 primeList[i]는 i가 소수인지 여부를 나타내고, 
        primeList[n-i]는 n-i가 소수인지 여부를 나타냅니다. 
        만약 i와 n-i가 모두 소수라면, 이 두 소수의 합으로 짝수 n을 나타낼 수 있습니다. 
        이것이 골드바흐의 추측입니다.
        """

    """
    예를 들어, n이 10일 때를 살펴봅시다. 
    i가 3이고 n-i가 7인 경우, 3과 7은 모두 소수이므로 10은 소수의 합으로 나타낼 수 있습니다. 
    따라서 ans를 증가시킵니다.
    
    이런 식으로 i를 증가시키면서 모든 가능한 조합에 대해 소수의 합으로 나타낼 수 있는지를 확인하고,
    가능한 경우마다 ans 값을 증가시켜서 최종적으로 골드바흐 파티션의 수를 구하게 됩니다.
    
    """
    print(ans)

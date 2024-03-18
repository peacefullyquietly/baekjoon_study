# 요세푸스 문제

N, K = map(int, input().split())
queue = [i for i in range(1, N + 1)]  # 큐 초기화

result = []  # 제거된 요소들을 저장할 리스트
idx = 0  # 현재 큐에서 제거될 요소의 인덱스

for _ in range(N):
    idx = (idx + K - 1) % len(queue)  # 큐의 길이로 나눈 나머지를 이용해 다음 제거될 요소의 인덱스 구함
    result.append(str(queue.pop(idx)))  # 해당 인덱스의 요소를 제거하고 결과 리스트에 추가

print("<", ", ".join(result), ">", sep='')  # 결과 출력

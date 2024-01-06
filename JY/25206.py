import sys
input = sys.stdin.readline

transcript = []
grade_standard = {"A+": 4.5, "A0": 4.0, "B+": 3.5, "B0": 3.0,
                  "C+": 2.5, "C0": 2.0, "D+": 1.5, "D0": 1.0, "F": 0.0}

for i in range(20):
    lecture, score, grade = list(map(str, input().split()))
    if grade == 'P':
        pass
    else:
        transcript.append([lecture, float(score), grade])

result = 0.0
cnt = 0
for j in transcript:
    if j[2] == "F":
        cnt += j[1]
        pass
    else:
        result += j[1] * grade_standard.get(j[2])
        cnt += j[1]
if len(transcript) == 0:
    print("0.000000")
else:
    print(f'{result/cnt:.6f}')

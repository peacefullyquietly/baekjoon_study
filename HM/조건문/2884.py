#알람시계
H,M=input().split()
H=int(H)
M=int(M)

if M<45: #분이 45분보다 작을때
    if H==0: #자정일때
       H=23
       M=M+60
    else: #0시보다 크면
      H=H-1
      M=M+60
print(H,M-45)
 
  


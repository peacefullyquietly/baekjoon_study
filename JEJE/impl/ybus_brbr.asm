section     .text
global      main
main: 
    mov     edx,len   
    mov     ecx,msg   
    mov     ebx,1   
    mov     eax,4   
    int     0x80   
    mov eax, 0
    ret  
section     .data
msg     db  '비와이'
len     equ $ - msg
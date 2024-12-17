; SPDX-License-Identifier: AGPL-3.0-or-later
; NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
section .text
global main
main:
    mov edx, len
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov eax, 0
    ret
section .data
msg db "Hello World!", 0xa
len equ $ - msg
bits 32 
global _start

Section .text
_start:
    mov eax,1
    mov ebx,5
    int 0x80


;exit(5);

Section .data

str: db "Hello",0x0a, 0x00

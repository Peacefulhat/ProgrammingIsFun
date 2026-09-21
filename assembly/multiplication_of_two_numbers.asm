section .bss
	buffer resb 20		;buffer to store charcters.
	
global _start:
	
_start:
	mov eax,0xffffffff
	mov ebx,1
	mul ebx
	
	mov rax ,1
	mov rdi ,1
	mov rsi ,buffer
	mov rdx, 20
	;Exit 
	mov edi,eax
	mov rax,60
	syscall
	hlt
	

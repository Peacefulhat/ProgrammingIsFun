global _start:
	
_start:
	mov r9,23
	mov r10,10
	sub r9,r10
	mov rax , 60
	mov rdi,r9
	syscall
	hlt

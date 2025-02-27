global _start
	
_start:
	mov r8,0x23
	mov r9,0x25
	add r8,r9
	mov rax, 60
	mov rdi, r8
	syscall
	hlt

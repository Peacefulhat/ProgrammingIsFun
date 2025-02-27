global _start:

_start:
	mov rax,27
	mov rsi, 0
	
top:
	cmp rax,1
	je done
	add rsi,1
	mov rbx,2		;put 2 in rbx
	mov rdx,0		;zero out rdx
	mov rcx,rax		;save rax
	div rbx			;divide rax by 2
	mov rax,rcx		;restore rax
	cmp rdx,0
	je even
	
	;odd number
	mov rbx,3
	mul rbx
	add rax,1
	je over
even:
	;even number
	mov rdx,0
	mov rbx,2
	div rbx
over:
	jmp top
	
done:
	mov rdi,rsi
	mov rax,60
	syscall
	hlt
	
	

global _start
_start:
    mov rax, 60        ; syscall: exit
    mov rdi, 234234    ; exit code
    syscall            ; invoke syscall

## Variation and commonality in Assembly


> [!NOTE] Note
> Each Processor has its own machine code, and thus it own assembly language.

**Example**:

**Consider the byte sequence** *`08 ef 90`* .

**intel `X86-64`:**

**byte**    **c`pu_asm`**
*`08 e5   or ch,ah `* ;here is 2 byte command 
*`90     nop`*      ;; here it is a single byte command, telling just go to the next instruction.

**Motorola `m68hc11`**

**byte**   **`cpu_asm`**
*`08      inx`*     ;;increment x register
*`e5 90 bitb 0x90,x`*  ;;`bitb`,bit test "and" operation, between `0x90` and register x.

>[!NOTE] NOTE
>CPU is free to guess what every these sequence of bytes are, every cpu interprets the byte sequence differently.(it depends on cpu architecture)

## Dialects of Assembly Language

**Dialect:**
_DIALECT_ is a regional variety of language distinguished by features of vocabulary, grammar, and pronunciation from other regional varieties.

There can be different dialects of assembly language. The X86 architecture has two: the intel syntax (that we will mainly use) and the AT&T syntax(that is used by the GNU tools). You'll see both.

**intel** 
*`48 83 ec 08       sub rsp,0x8`*
*`48 8b 05 c9 ef 01 00   mov rax,[rip+0x1efc9]`*

**AT&T**
*` 48 83 ec 08  sub $0x8, %rsp`*
*`48 8b 05 c9 ef 01 00  mov 0x1efc9(%rip),%rax`*

## Assembler and Dis-assembler Dialects
- Each assembler has its own directives,  macro language , special syntax. This is also true for each dis-assembler.
- This is not a unusual. Different compilers, even for standardized languages,may have different compiler directives.
### Assembly code example
### `Nasm`
```
global main
extern puts
section .text

main:
	push rsp
	mov rbp, rsp 
	lea rdi,[rel msg]
	call putswrt ..plt
	mov edi, 0
	pop rsp
	ret
	section .data
	msg:db "Hello,World!",0
```

### `GAS`
```
.intel_syntax noprefix
.global main
.extern puts

.text

.main
	push rsp
	mov rbp,rsp
	lea rdi, [msg + rip]
	call puts@plt
	mov edi, 0
	pop rsp
	ret
	.data
	msg .asciz "Hello,World!"
```

### Disassembly
##### `hello-nasm.o`
```
Disassembly section .text

0000000000000000 <main>:
0:54                       push rsp
1:48 89 e5                 mov  rbp,rsp
4:48 8d 3d 00 00 00 00     lea  rdi,[rip+0x0]
b:e8 00 00 00 00           call 10 <main+0x10>
10:bf 00 00 00 00          mov  edi,0x0
15:5c                      pop rsp
16:c3                      ret
```

##### `hello-gas.o`
```
Disassembly section .text

0000000000000000 <main>:
0:54                       push rsp
1:48 89 e5                 mov  rbp,rsp
4:48 8d 3d 00 00 00 00     lea  rdi,[rip+0x0]
b:e8 00 00 00 00           call 10 <main+0x10>
10:bf 00 00 00 00          mov  edi,0x0
15:5c                      pop rsp
16:c3                      ret
```

- Here it look like they produced identical code... and they did!, but assemblers generate other information , like relocation's, and those differ.if you fully link these files, you will end up with slightly different executable.

## Assembly Language Common Elements
- Because there are different machine codes, there are also different assembly languages... but modern assembly languages have several things in common.(some of this comes from the influence of the `BCPL` and C programming languages.)

<hr>

- Execution proceeds in the fetch-decode-execute cycle.
- An instruction pointer (program counter) determines the location of the next fetch.
- control flow is handled by conditional relative branches or by unconditional jumps.
- There is a simple subroutine system where the return address is pushed on the stack (x86) or held in a register (ARM) until a return instruction is executed
- Registers(named storage) are used to hold intermediate value and to control the operation of the processor (there are "stack machines") but still have an instruction pointer)
- A stack is used for local variable storage and usually for subroutine return 
- Programs directly reference memory by address and use primitive types
- A condition register contains flags modified by instructions
- Bit-oriented operations are important , like rotate,shift,and ,or and not
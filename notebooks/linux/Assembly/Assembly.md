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
- It is convenient that the program counter (PC)/instruction pointer (IP) always points to the next linear instruction, since it simplifies calling and returning and make them faster 
	- Aside: the 6502 has to waste cycles because it stores the PC on the stack off-by-one and has to increment it on return 
- It is common convention that the stack pointer(SP) point to the last item pushed onto the stack.
	- Aside: the 6502 doesn't do this, either but points to the first open address.
- The usual convention is that, given two possible addresses for a thing(the last item pushed or first open spot) the higher address is chosen, often because it tends to be aligned(the low bits are zero)
##### There is a lot of commonality in assembly languages, and instructions follow the following basic format:

**mnemonic**:
- A <strong>mnemonic</strong> identifies the main operation (though there may be others).
- This is usually short, and can be fairly obvious(like add and sub)or not-so-obvious(like `pslrq`).
- Example:
	**`mov rax, 1`** : `mov` is mnemonic and here This operation "move".This operation is used to copy the data.here its coping value one to the `rax` register.
**Operands**:
- The **operands** are the explicit arguments to the operation. There may be additional implicit arguments.
- order of arguments matters.
- `x86` uses `<mnemonic> <destination> <source>`.And this order is common among processors.`Arm` does the same thing.
- `AT&T` uses `<mnemonic> <source> <destination> `.
- Example:
	**`mov rax, 1`**: here the arguments are `rax` and a literal value `1`.

###### Some example of mnemonic with different length of arguments.
`clc` : takes no operand just 
and.
`inc`: take one argument, just increment the value by one.
`add eax,ebx`: takes two operands, its `eax+=ebx`
`imul eax,ebx,7`: can take one argument,two argument or three, here its `eax=ebx*7`
`movsb`: is a string oriented instruction,takes three implicit arguments, implicit register `<source>`:`rsi`
`<destination>`:`rdi`, and a `direction register`: which is conditional code register etc. **Here its moving data byte by byte**.
>[!NOTE]
>Intel operations usually have zero , one, or two operands. A few (like `imul`) can have three. There can be both explicit and implicit arguments as well as optional operands.
>
> In some cases `disassemblers` will show implicit arguments as if they were explicit operands and you could change them. That not always true.

##### Assembly instructions - Implicit and Explicit:
- Every assembly language has some oddities and the `X86` instruction set has example of most of those.
- The **Division** operation has one explicit operand and one implicit argument and uses three registers.
- only the divisor is named explicitly and can be specified the other register are implicit and fixed
- Example:
	- ` div rbx`:divide the 128 bit integer in `rdx:rax` by the 64 bit integer `rbx` and store the 64 bit quotient in `rax` and the 64 bit remainder in `rdx`.
	- Generate an exception if the result won't fit.
`rbx` :`rdx`         `rax`
      high 64 bit low 64 bit
quotient: store in `rax`.
remainder: store in `rdx`.

## Assembly instruction - Addressing Modes:

- The value of each operand can be provided in a few different ways. We call this the addressing mode for each operand .
- Some processor have many addressing modes, including fancy modes like direct indexed, indirect indexed, implied, zero page, etc
- The `x86` has (arguably) four "high-level" modes:
	- immediate
	- register
	- memory
	- rip-relative
	Aside: Addressing mode available vary by processor, but again, there are many commonalities.
##### Immediate Addressing mode
- The value of the operand is given as a literal constant.
- Example:
	- `mov rax, 0x2f4e0800`: here hex value is the immediate value.
##### Register Addressing Mode
- The value of the operand is the current content of a register.
- Example:
	- `mov rax, rcx`: here `rcx` is like Register value.
##### Memory Addressing Mode
- The value of the operand is the current content of a memory address.
- Memory References are enclosed in square brackets and can be specified in fairly complex ways.
- Example:
	- `mov rax, [rdx+16]`: here term is square bracket is memory reference.
	- In this case the memory address is taken by adding 16 to the content of the register `rdx`.so this operand is a memory operand composed of a register and an immediate value.

##### rip-Relative Addressing Mode
- The value of the operand depends on the current value of the instruction pointer rip.
- This is a trick to implement position independent code.
- Example:
	- `lea rax, [rel msg]` 

## Writing Assembly
- you the following tools to use when writing assembly.
- operations
- register
- memory
- stack
- conditional branches
- unconditional jumps
That's pretty much everything.

**`//Todo:Risc and Cisc.`**

## Instruction set architecture

#### Programming view:
![[programming_view.png]]

#### Some X86 Architecture: 16-bit addresses(64 `kib`,2^16)

16-bit general purpose registers
- Accumulator : `ax`
- base: `bx`
- counter: `cx`
- data: `dx`
- stack pointer: `sp`
- (stack)base pointer: `bp`
- source index: `si`
- destination index: `di`
- instruction pointer: `ip`
>[!NOTE]
>The `ax,bx,cx and dx` register are `<high> <low>` byte-addressable.
>`ax=ah.al` here `ah has high 8 bits and al has low 8 bits`
>`bx=bh.bl`
>`cx=ch.cl`
>`dx=dh.dl`
>
>8-bits:byte
>16-bits:word

#### Some X86 Architecture: 32-bit addresses(4 GB)
Extended general purpose register.
- `eax,ebx,ecx,edx`
- `esp,ebp`
- `esi,edi`
- `eip`
 >[!NOTE]
> - Even though `sp and ip` are still usable, the stack pointer is now `esp` and the instruction pointer `eip`,because memory addresses are always 32 bit wide.

Register aliasing:
`eax`:: (16 bits).`ax`
	 (16 bits).`ah.al`
8 bits :: byte
16 bits :: word
32 bits :: `dword` (double word)

#### Some X86_64 (`amd64`) Architecture:64-bit addresses (16 `EIB`)
"r" is for register.
- `rax,rbx,rcx,rdx`
- `rsp,rbp`
- `rsi,rdi`
- `rip` 
>[!NOTE]
>Even though `esp and eip` are still usable,the stack pointer is now `rsp` and the instruction pointer is now `rip`, because memory addresses are always 64 bit wide.

But also...
- `r8,r9,r10,r11,r12,r13,r14,r15`
- (`rax through rdi` count as `r0-r7`)
 
Aliasing:
`rax`
=(32 bits).`eax`
=(32 bits).(16 bits).`ax`
=(32-bits).(16 bits).`ah.al`

8 bits: byte
16 bits: word
32 bits: `dword` (double word)
64 bits: `qword` (quad word)

`Todo: look into the documentation for floating point registers`

#### Segment register
code segment :: `cs`
Data segment :: `ds`
stack ::`ss`
Extra segment registers :: `es, fs, gs`
The extra segment register are usually used by operating system.

### flags (16 bit)
- carry `cf`
- parity `pf`(even =1 , odd=0)
- adjust/Auxiliary `af`(4-bit carry)
- zero `zf`
- sign `sf`
- trap `tf`(single-step)
- interrupt Enable `if`(allowed = 1)
- direction `df`(increment = 0)
- overflow `of`
- privilege `ipol`(2 bits)
### more eflags (32 bit)
- Resume `rf`
- virtual 8086 `vm`(compatibility =1 )
- alignment Check `ac`(enable=1)
- virtual interrupt `vif`
- virtual interrupt pending `vip`
- cpu id `id`
- virtual address Descriptor `vad`(allowed =1)

### more `rflags` (64 bit)
- Reserved , current not much used.

You cannot access the register directly but you can manipulate it using special instructions.
- `pushf` pushes the flags register content on top of the stack.
- `popf` loads the flags register from the top of the stack.
- similar instruction extends to `eflags(pushfd/popfd)`and `rflags(pushfq/popfq)`
- `lahf` moves flags bits 0-7 into `ah`
- `sahf` moves `ah` into bits 0-7 of flags![[flags.png]]
#### Special Registers:

**rip**:
- The instruction pointer is rip, you can't access it directly(you can't `mov rax,rip`) but you can use it with rip-relative indexing, and there are tricks to read it during program execution.
**`rsp`**:
- The stack pointer is `rsp`. you can use it like any other register , including doing math with it (`sub rsp,16`). A common mistake is to use `esp` in place of `rsp`. only `rsp` is the stack pointer,because addresses have 64 bits.
**`rbp`**:
- The base pointer is `rbp`. it is really just another register, but by convention it often holds the address of the current stack frame and is used to locate local variables stored on the stack. with in a procedure the stack pointer `rsp` may change ,but the base pointer `rbp` is (usually)fixed.
- if the base pointer is not needed, then code might use it as just another general-purpose register.
>[!NOTE]
>A stack frame is the area of the stack that belongs to a specific routine. it usually hold temporary or local variables

**`rsi and rdi`**:
- The **source** and **destination** register `rsi and rdi` are used by instructions that move block of data (along with the count register `rcx` and the direction flag `df`). Otherwise you can use them just like any other register.

### An Example:
```
mov rax,60
mov rdi,0 
syscall
hlt
```

Let's create an assembly program. for now we will just start up and then exit.

we will use the *exit* system call;
```
nasm -f elf64 filename.asm
```
only for Linux.
we can see the .o file using obj dump
```
objdump -d -Mintel filename.o
```
- `Mintel`: is for intel dialect.

- Assembler does not know how things will be laid out in memory , so it cannot fill everything in, and defers that to the linker by creating re-locations. 
-   ![[disassembly.png]]
- `0: ,5:,a:,c:` are the offset address of each instruction.
- Next we link the file to create executable.
- *Linking* resolves (most of ) the re-locations.These are usually references to symbols in other files, to library code, or to well-known symbols(like _start or main) .
- Linking connects ("links")parts of programs , entire programs, or libraries.
- The linker on most platforms is called **`ld`**.Here the linker looks for a _start symbol but does not find one. it assumes the first address in the file is the start.
- ![[linking.png]]
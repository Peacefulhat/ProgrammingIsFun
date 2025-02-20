## Variation and commonality in Assembly


> [!NOTE] Note
> Each Processor has its own machine code, and thus it own assembly language.

**Example**:

**Consider the byte sequence** *`08 ef 90`* .

**intel X86-64:**

**byte**    **cpu_asm**
*`08 e5 `* or ch, ah ;here is 2 byte command 
*`90`*    nop  ;; here it is a single byte command, telling just go to the next instruction.

**Motorola m68hc11**

**byte**   **cpu_asm**
*`08 `*   inx          ;;increment x register
*`e5 90`* bitb 0x90,x  ;;bitb,bit test "and" operation, between 0x90 and register x.

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
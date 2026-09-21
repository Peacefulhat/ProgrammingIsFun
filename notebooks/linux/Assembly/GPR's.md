## General purpose registers and their uniqueness

>[!NOTE]
>In `x86_64`, there are 16 general purpose registers.While they can often used interchangeably, each has unique characteristics or conventional uses.

## `rax` (accumulator register)

- **Purpose**:
	- Traditionally used for arithmetic operation, function return value and `syscall` return values.
	
- **Implicit uses:** 
	- *Multiplication/Division:*
		- `mul and div use rax for storing results`
	- *Return values:*
		- Function return values (integer , pointer) in `rax`(system V `ABI`). 
	- `syscall`Return: 
		- When calling `syscall` , the return value (`e.g. file descriptor ,error code) is placed in rax.
		
- **Best Practices**:
	- use for return values in functions.
	- avoid modifying it before a function returns if it holds a meaningful result.
	
## `rbx` (base register)

- **Purpose**:
	- Historically used as a pointer register, often preserved across function calls.

- **Implicit uses:** 
	- None in modern `x86_64`, but it was often used in old `x86` Dos-based system for base addressing.
	
- **Best Practices**:
	- Since it's a `calle-saved` register (must be preserved in function calls) avoid using it unless necessary.
	
## `rcx` (counter register)

- **Purpose**:
	- Used as a loop counter and for certain system calls.

- **Implicit uses:** 
	- *Loop instructions:*
		- The loop instruction decrements `rcx` and jumps if it's not zero.
	- *String instructions:*
		- `Rep movsb,rep stosb,etc.`,use `rcx` as counter.
	- *`syscall` Arguments:* 
		- In some OS conventions, `rcx` is used as the fourth argument.
		
- **Best Practices**:
	- use it for loops and counted operations.
	- be careful when using `syscall`, as it might overwrite `rcx`.
	
## `rdx` (data register)

- **Purpose**:
	- often used for storing extra data in multiplication and division.

- **Implicit uses:** 
	- *multiplication(`mul`):*
		- Stores the upper 64 bits of the result.
	- *division (`div`):*
		- Holds the remainder.
	- *`syscall` Arguments:* 
		- holds the third argument for system calls.
		
- **Best Practices**:
	- use when dealing with large multiplication or divisions
	 
## `rsi` (source index register)

- **Purpose**:
	- used as a source pointer for memory operations.
	
- **Implicit uses:** 
	- *String instructions:*
		- `movs,stos,scas etc..,`use `rsi` as source
	- *`syscall` Arguments:* 
		- second argument in the `syscall`.
		
- **Best Practices**:
	- useful for memory operations especially with `rep ,movsb`
	- Avoid modifying it before a `syscall` if it holds an argument. 

## `rdi` (destination index register)

- **Purpose**:
	- used as a destination pointer for memory operations.
	
- **Implicit uses:** 
- 
	- *String instructions:*
		- `movs ,stos,scas,etc.,`use `rdi` as a destination.
	- *`syscall` Arguments:* 
		- first argument in `syscall`.
		
- **Best Practices**:
	- use when copying or scanning memory.
	- Ensure it has the correct value before `syscall`.
	 
## `rbp` (base pointer register)

- **Purpose**:
	- Traditionally used to store the base of the stack frame in functions.
	
- **Implicit uses:** 
	- *Stack frame:* 
		- in function prologues/epilogues, `rbp` is used to maintain a stable stack frame.
		
- **Best Practices**:
	- if using frame pointers, do not overwrite `rbp` in a function.
	- modern compiler use **frame-pointer omission**,(FPO) ,freeing `rbp` for general use.
	
## `rsp` (stack pointer register)

- **Purpose**:
	- always points to the top of the stack.
	 
- **Implicit uses:** 
	- *push / pop  instructions:*
		- `push /pop ` modify `rsp`.
	- *function calls:* 
		- (`call & ret`): `rsp` tracks the return address.
		
- **Best Practices**:
	- do not modify `rsp` arbitrarily
	- use `sub rsp,size and add rsp, size` when allocating / `de`-allocating stack space.
## `r8 - r15` (extended general purpose register)
- **Purpose**:
	- additional registers introduced in `x86_64`.
	
- **Implicit uses:** 
	- *function arguments:*
		- In `system V ABI` (`linux,macOs`) , `r8-r9` hold the 5th and 6th function arguments.
	- *general storage: * 
		- These are purely general-purpose.
		
- **Best Practices**:
	- useful when optimizing register allocation in function calls.
	- be mindful of `caller-saved vs. callee-saved` rules.

### caller-saved:
- These registers might be overwritten by a function, so the caller must save them if needed.
### `callee`-saved:
- Functions must preserve these register and restore them before returning.

| Register  | caller-saved | `calle`-saved          |
| --------- | ------------ | ---------------------- |
| `rax`     | yes          | no(holds return value) |
| `rcx`     | yes          | no                     |
| `rdx`     | yes          | no                     |
| `rsi`     | yes          | no                     |
| `rdi`     | yes          | no                     |
| `r8-r11`  | yes          | no                     |
| `rbx`     | no           | yes                    |
| `rbp`     | no           | yes                    |
| `rsp`     | no           | yes                    |
| `r12-r15` | no           | yes                    |

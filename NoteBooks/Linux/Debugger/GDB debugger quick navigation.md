
## 1. Compile with Debug Info
```bash
gcc -g your_file.c -o your_program
```
Use `-Og` for minimal optimization with debug friendliness.

## 2. Start GDB
```bash
gdb ./your_program
```
You can also run and pass arguments:
```bash
gdb --args ./your_program arg1 arg2
```

## 3. Running the Program
```bash
run [args]     # Run with optional args
r              # Shortcut for run
start          # Run and stop at main()
```

## 4. Breakpoints
```bash
break main
b file.c:42
b function_name
info breakpoints
clear           # Clear breakpoint at current line
delete [n]      # Delete breakpoint n
```

### Conditional Breakpoints
```bash
break foo if x > 10
```

## 5. Stepping Through Code
```bash
next (n)        # Step over
step (s)        # Step into
finish          # Run until function returns
continue (c)    # Resume execution
until           # Run until a line > current line
```

## 6. Inspecting Variables
```bash
print x
p *ptr
set var x = 42
info locals
info args
display x       # Auto print on each stop
undisplay n     # Remove display
```

## 7. Viewing Memory
```bash
x/FMT address
```
Examples:
```bash
x/4xw ptr        # 4 words in hex
x/8xb &array     # 8 bytes
x/s ptr          # Print string at ptr
```

## 8. Source Navigation
```bash
list             # List current code
list 25          # Around line 25
list function    # Show function source
edit             # Open source in default editor
```

## 9. Call Stack Navigation
```bash
backtrace (bt)
frame n          # Select frame
up/down          # Navigate frames
info frame       # Detailed frame info
```

## 10. Watchpoints
```bash
watch var
rwatch var
awatch var
```
**Note:** Only works with variables in memory (not registers).

## 11. Signal and Exception Handling
```bash
catch throw                # C++ exceptions
catch catch                # C++ catch blocks
catch signal SIGSEGV       # OS-level signals
handle SIGSEGV stop print
```

## 12. Threads and Concurrency
```bash
info threads
thread n        # Switch to thread n
thread apply all bt  # Stack traces for all threads
```

## 13. Debugging Shared Libraries
```bash
info sharedlibrary
sharedlibrary libm.so
set solib-search-path ./libs
```

## 14. Debugging Core Dumps
```bash
ulimit -c unlimited   # Enable core dumps
./program             # Let it crash
gdb ./program core    # Open core file
```
Use `bt`, `info locals`, and `frame` to inspect the crash site.

## 15. Scripting and Custom Commands
- Create `.gdbinit` in home/project dir:
```gdb
set pagination off
set print pretty on
```
- Define macros:
```gdb
def mymacro
  print x
  next
end
```

## 16. TUI Mode
```bash
gdb -tui ./your_program
```
- Ctrl+X A to toggle layout.
- Displays code alongside the GDB prompt.

## 17. Remote Debugging with GDBserver
```bash
gdbserver :1234 ./your_program
# On host:
gdb ./your_program
(gdb) target remote host_ip:1234
```

## 18. Reverse Debugging (Experimental)
```bash
enable record
record
reverse-step
reverse-continue
```

## 19. Useful Commands Summary
```bash
info registers       # CPU registers
info files           # Show binary info
info source          # Current source file
info program         # Status of debuggee
```

## 20. Exit GDB
```bash
quit
```

## References
- GDB manual: https://sourceware.org/gdb/current/onlinedocs/gdb
- GDB cheatsheet: https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
- Valgrind integration: https://valgrind.org


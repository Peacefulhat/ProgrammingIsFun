## 1. Build in Debug Mode
- Open your project in **Visual Studio**.
- Set configuration to **Debug**.
- Press **Ctrl+Shift+B** to build.
- Ensure optimization is disabled (Project Properties > C/C++ > Optimization > Optimization = Disabled (/Od)).

## 2. Start Debugging
- **F5**: Start debugging (with breakpoints).
- **Ctrl+F5**: Run without debugging.
- Use **Debug > Start Debugging** from the menu as an alternative.

## 3. Breakpoints
- Click in the left margin or press **F9**.
- Right-click breakpoint for:
  - **Conditions** (e.g., break when `x == 5`)
  - **Hit Count** (e.g., break every 3rd time)
  - **Action** (log message without breaking)

## 4. Step Execution
- **F10** – Step Over
- **F11** – Step Into
- **Shift+F11** – Step Out
- **Ctrl+Shift+F10** – Run to Cursor
- **Ctrl+Alt+F9** – Force run to a selected function

## 5. Debugger Windows
- Open via **Debug > Windows > [Name]**
- **Autos**: Shows variables used in the current and previous statement.
- **Locals**: All local variables in scope.
- **Watch**: Custom expressions.
- **Immediate Window (Ctrl+Alt+I)**: Evaluate expressions and call functions.
- **Call Stack**: View and navigate the function call hierarchy.
- **Threads**: Inspect and switch between threads.
- **Modules**: View loaded modules and symbols.

## 6. Memory & Registers
- **Memory Windows (Memory 1–4)**: View raw memory.
- **Registers**: View CPU register values.
- **Disassembly**: Right-click > "Go to Disassembly" or press **Ctrl+Alt+D**.

## 7. Edit & Continue
- Modify your source while debugging is paused.
- Automatically recompiles and continues execution.
- Limitations:
  - Can't add new functions/types.
  - Can't edit in optimized Release builds.

## 8. Data Tips & Visualization
- Hover over variables for pop-up info.
- Use **DataTips** to pin variables during debug.
- Built-in support for STL containers.
- Custom visualizations via `.natvis` files in project directory.

## 9. Exception Settings
- **Debug > Windows > Exception Settings**:
  - Break on specific exceptions (e.g., `std::out_of_range`).
  - Break on first chance exceptions.

## 10. Dump Debugging
- Open crash dumps via **File > Open > Project/Solution > Dump File**.
- Attach symbols via **Tools > Options > Debugging > Symbols**.

## 11. Attach to Process
- Use **Debug > Attach to Process** to debug running applications.
- Filter for your application name.
- Supports mixed-mode debugging (native + .NET).

## 12. Symbol & Source Configuration
- Configure symbols:
  - Tools > Options > Debugging > Symbols.
  - Add Microsoft Symbol Servers and local cache paths.
- Configure source server support to pull code from source repositories.

## 13. Remote Debugging
- Use **Remote Tools for Visual Studio** to debug apps on another machine.
- Match architecture and version.
- Requires firewall exception and permissions.

## Quick Tips
- **Ctrl+Alt+Q**: QuickWatch
- **Ctrl+Alt+U**: Class View
- **Ctrl+Alt+H**: Call Hierarchy
- Use **Tracepoints** to log debug info without stopping execution.
- Enable **Diagnostic Tools** for CPU/memory profiling while debugging.

## Further Help
- **Visual Studio Documentation**: [https://learn.microsoft.com/en-us/visualstudio/debugger/](https://learn.microsoft.com/en-us/visualstudio/debugger/)
- Keyboard shortcut reference: **Help > Keyboard Mapping Scheme**



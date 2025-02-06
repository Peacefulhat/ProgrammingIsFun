#### SQL-mode
- Emacs’ built-in sql-mode allows you to run SQL queries directly in a buffer and send them to MySQL. 
##### Steps to Set up
- open a new buffer and set it to **`sql-mode`**.
- command:: M-x sql-mode.
- start an interactive My SQL session. 
- command:: M-x sql-mysql
- you will be prompted for connection details (host name, password ,database,port).
##### Execute queries from the sql buffer:
- **`C-c C-c`** -> Execute the current sql statement.
- **`C-c C-r`** -> Execute the selected region.
- **`C-c C-s`**-> Send the entire buffer.

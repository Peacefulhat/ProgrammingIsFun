### Leader Keys:
- Meta(M): alt-key
- control(C): control-key
- backspace(DEL)
- Enter:RETURN
### Movement Keys:
- C-v: Move forward one screenful.
- M-v: Move backward one screenful.
- C-l:  Find the cursor, and note what text is near it.  Then type C-l.
   Find the cursor again and notice that the same text is still near
   the cursor, but now it is in the center of the screen.
   If you press C-l again, this piece of text will move to the top of the screen . Press C-l again, and it moves to the bottom.
- C-f:	Move forward a character.
- C-b:	Move backward a character.
- M-f:	Move forward a word.
- M-b:	Move backward a word.
- C-n:	Move to next line.
- C-p:	Move to previous line.
- C-a:	Move to beginning of line.
- C-e:	Move to end of line.
- M-a:	Move back to beginning of sentence.
- M-e:	Move forward to end of sentence.
- M-<:  Move to start of file.
- M->:  Move to end of file.
### Repeat command:
  - C-u argument {command}: argument is how many time you want to execute the command.

 - C-u argument C-v: will move courser to argument times.

- C-g: for clearing commands and quitting commands that is taking too long to execute.

### Windows:
- C-x 1: one window (i.e, kill all the other windows).

### Inserting and Deleting:
- {DEL}:   Delete the character just before the cursor.
- C-d:     Delete the next character after the cursor.
- M-{DEL}: Kill the word immediately before the cursor.
- M-d:	  Kill the next word after the cursor.
- C-k:     Kill from the cursor position to end of line.
- M-k:     Kill to the end of the current sentence.
- C-{space}:Set a mark.(select a section of text).
  can be used with C-u
- C-y: This will paste the deleted lines by C-k if there are any.
- M-y: After you have done C-y to get the most recent kill, typing
       M-y replaces that yanked text with the previous kill.  Typing M-y again and again brings in earlier and earlier kills.
### Undo:
- C-/: will perform undo operation.
### Copy:
Copy (Kill) Command:
- To copy text (which Emacs refers to as "killing"), you can use:
      C-space (set the mark) to start selecting text.
        Move the cursor to select the region.
        M-w to copy the selected text to the kill ring.

### Cut (Kill) Command:
- Similar to copying, you can cut text using:
        C-Space to set the mark.
        Move the cursor to select the text.
        C-w to cut the selected text to the kill ring.

### Paste (Yank) Command:
- To paste text from the kill ring, use:
        C-y to yank (paste) the most recent killed text.
### Cycle Through Kill Ring:
- You can cycle through previously killed (copied or cut) items using: M-y after C-y to cycle through the kill ring.

### Copying Entire Buffer:
- To copy the entire buffer, you can use:
    C-x h to mark the whole buffer, then M-w to copy it.
### With Escape key:
Marking Text:
- To set the mark, you can use C-space or C-@, but if you want to use Escape, you can press Escape followed by x to invoke commands interactively.
### Copying Text:
- After setting the mark with C-Space, you can press Escape followed by w to copy (kill) the selected region (equivalent to M-w).

### Pasting Text:
- To paste (yank) the most recent killed text, use C-y. If you want to use the escape sequence, you can use Escape followed by y to yank the last entry in the kill ring after killing something.

Using Escape as Meta:
- You can also use Escape as a substitute for Alt. For example, Escape followed by b would be equivalent to M-b (move back a word).

### File,Buffer:
- C-x C-f    Find file
- C-x C-s	Save buffer to file
- C-x s		Save some buffers to their files
- C-x C-b	List buffers
- C-x b		Switch buffer
- C-x C-c	Quit Emacs
- C-x 1		Delete all but one window
- C-x u		Undo
- C-x f      give the margin setting you want.

### Searching:
- Emacs can do searches for strings (a "string"  is a group of contiguous characters) either forward through the text or backward through it.
Searching for a string is a cursor motion command; it moves the cursor to the next place where that string appears.

- C-s: for forward search from cursor to end of file.
- after typing the string, press C-s to move in forward to the next string.
- use DEL to move to the previous position of string.
 
- C-r: for backward from cursor to end of file.
- after typing the string, press C-r to move in backward to the next string.
- RETURN terminate a search.

### Multiple Windows:
- One of the nice features of Emacs is that you can display more than one window on the screen at the same time.
- C-x 5 1 or C-x 1:   Delete all other windows.
- C-x 5 2 or C-x 2:  Split window, above and below.
- C-x 5 0 Or C-x 0:Delete this window.
- C-x 3:   Split window, side by side.
- C-M-v:   Scroll other window.
- C-x 5 o Or C-x o: Switch cursor to another window.
- C-x 5 b Or C-x 4 b: Select buffer in other window.
- C-x 5 C-o Or C-x 4 C-o: Display buffer in other window.
- C-x 5 f Or C-x 4 f: Find file in other window.
- C-x 5 r Or C-x 4 r: Find file read-only in other window.
- C-x 5 d or C-x 4 d:  Run Dired in other window.
- C-x 5 . or C-x 4 . : Find tag in other window.
- C-x ^:   Grow window taller.
- C-x {:   Shrink window narrower.
- C-x }:   Grow window wider.
### Some useful commands:
- M-x gdb: for gdb supported testing of programs.
- M-x ediff: Emacs can compare two file and highlight their differences.
- M-x dired: To enter dired mode , you can use C-x C-q to make dired buffer editable.
- M-x list-packages: for downloading packages for emacs.
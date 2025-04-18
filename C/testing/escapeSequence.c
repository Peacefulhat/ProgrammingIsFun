#include<stdio.h>
void escapeSequences(){
//Newline (\n):
//Moves the cursor to the beginning of the next line.
printf("Hello\nWorld");
// Output:
// Hello
// World

//Tab (\t):
// Moves the cursor to the next tab stop.
printf("Hello\tWorld");
// Output:
// Hello   World

//Backspace (\b):
// Moves the cursor back one position.
printf("Hello\bWorld");
// Output:
// HellWorld

//Carriage Return (\r):
//Moves the cursor to the beginning of the current line.
printf("Hello\rWorld");
// Output:
// Worldlo

//Double Quote (\"):
//Represents a double quote within a string.
printf("He said, \"Hello!\"");
// Output:
// He said, "Hello!"

//Single Quote (\'):
//Represents a single quote within a character constant.
char myChar = '\'';

//Backslash (\\):
//Represents a literal backslash.
printf("This is a backslash: \\");
// Output:
// This is a backslash: \

//Alert/Bell (\a):

//Produces an audible or visible alert
printf("Beep!\a");

//Vertical Tab (\v):
//Moves the cursor to the next vertical tab stop.
printf("Hello\vWorld");
// Output:
// Hello
//      World

//Question Mark (\?):
//Represents a literal question mark.
printf("What?\?");
// Output:
// What?

}
int main(){
  escapeSequences();
  return 0;

}

#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000

static char allocbuf[BUFFERSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];
char *alloc(int n) {
  if (allocbuf + BUFFERSIZE - allocp >= n) {
    char *p = allocp;
    allocp += n;
    return p;
  } else {
    return NULL;
  }
}

void allocfree(char *p) {
  if (p >= allocbuf && p < allocbuf + BUFFERSIZE) {
    allocp = p;
  }
}

int getLine(char s[], int size) {
  int c, i = 0;
  while (i < size - 1 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int readline(char *lineptr[], int maxlines,char someBuffer[]) {
  int len, nlines = 0;
  char *p=someBuffer;
  char line[MAXLEN];

  while ((len = getLine(line, MAXLEN)) > 0) {
    if (nlines >= maxlines) {
      return -1;
    } else {
      line[len] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p+=len+1;
    }
  }
  return nlines;
}

void writeLines(char *lineptr[], int nlines) {
  for (int i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

int main() {
  int nlines =3;
  char someBuffer[MAXLEN];
  readline(lineptr,3,someBuffer);
  writeLines(lineptr,3);
}

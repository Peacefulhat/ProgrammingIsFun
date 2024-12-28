#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// manual memory management .

//In C, some variables are automatically allocated and deallocated when they come into scope and leave scope. We call these automatic variables. They’re your average run-of-the-mill block scope “local” variables. No problem.

//You can tell C explicitly to allocate for you a certain number of bytes that you can use as you please. And these bytes will remain allocated until you explicitly free that memory.

//It’s important to free the memory you’re done with! If you don’t, we call that a memory leak and your process will continue to reserve that memory until it exits.
//If you manually allocated it, you have to manually free it when you’re done with it.


/*
 ;;Reading in lines of arbitrary length.

i want to demonstrate two things with this full-blown example.

    Use of realloc() to grow a buffer as we read in more data.
    Use of realloc() to shrink the buffer down to the perfect size after we’ve completed the demo.

What we see here is a loop that calls fgetc() over and over to append to a buffer until we see that the last character is a newline.

Once it finds the newline, it shrinks the buffer to just the right size and returns it.*/


char *readline(FILE *fp)
{
    int offset = 0;   // count of character that pushed to buffer.
    int bufsize = 4;  // Preferably power of 2 initial size
    char *buf;        // The buffer
    int c;            // The character we've demo in

    buf = malloc(bufsize);  // Allocate initial buffer

    if (buf == NULL)   // Error check
        return NULL;

    // Main loop--read until newline or EOF
    while (c = fgetc(fp), c != '\n' && c != EOF) {

        // Check if we're out of room in the buffer accounting
        // for the extra byte for the NUL terminator
        if (offset == bufsize - 1) {  // -1 for the NUL terminator
            bufsize *= 2;  // 2x the space

            char *new_buf = realloc(buf, bufsize);

            if (new_buf == NULL) {
                free(buf);   // On error, free and bail
                return NULL;
            }

            buf = new_buf;  // Successful realloc
        }

        buf[offset++] = c;  // Add the byte onto the buffer
    }

    // We hit newline or EOF...

    // If at EOF and we read no bytes, free the buffer and
    // return NULL to indicate we're at EOF:
    if (c == EOF && offset == 0) {
        free(buf);
        return NULL;
    }

    // Shrink to fit
    if (offset < bufsize - 1) {  // If we're short of the end
        char *new_buf = realloc(buf, offset + 1); // +1 for NUL terminator

        // If successful, point buf to new_buf;
        // otherwise we'll just leave buf where it is
        if (new_buf != NULL)
            buf = new_buf;
    }

    // Add the NUL terminator
    buf[offset] = '\0';

    return buf;
}

void print(char *p){
  while(*p!='\0'){
    printf("%c",*p++);
  }
}
typedef struct {
  int x,y;
}point2d;

int main(){
  printf("Hello,World!\n");
  // malloc() accepts a number of bytes to allocate and return void pointer to that block of newly-allocated memory.
  point2d*p=(point2d*)malloc(sizeof(point2d));

  p->x=23;
  p->y=32;
  if(!p){
    printf("Hello,world\n");
  }
  printf("x:%d y:%d\n",p->x,p->y);
  //int *p = malloc(sizeof *p);  // *p is an int, so same as sizeof(int)
  free(p);
  printf("x:%d y:%d\n",p->x,p->y);
  
  char *pd=(char*)malloc(13);
  for(int i=0;i<13;i++){
    *(pd+i)='a';
    *(pd+i)=*(pd+i)+1;
  }
  
  for(int i=0;i<13;i++){
    printf("%c",*(pd+i));
  }
 
  free(pd);
  pd=NULL;
  printf("\n");
  for(int i=0;i<13;i++){
    // Dereferencing a NULL pointer results in undefined behavior
    printf("%d",i);
    //printf("%c",*(pd+i)); 
  }
  printf("\n");
  // calloc () , calloc(numberofelements,sizeof(int));
  // it clear the memory to zero
  
  int *newarray=calloc(10,sizeof(int));
  
  //memset(newarray,0,10*sizeof(int));
  int i=0;
  for(;i<10;i++){
    printf("%d",newarray[i]);
  }
  printf("\ni:%d\n",i);

  // Allocate space for 10 ints with calloc(), initialized to 0:
  //int *p = calloc(10, sizeof(int));

// Allocate space for 10 ints with malloc(), initialized to 0:
//int *q = malloc(10 * sizeof(int));
//memset(q, 0, 10 * sizeof(int));   // set to 0
//Again, the result is the same for both except malloc() doesn’t zero the memory by default.

  // realloc();// lets us resize the previsouly allocated memory.
  newarray=realloc(newarray,20*sizeof(int));
  i=0;
  for(;i<20;i++){
    printf("%d",newarray[i]);
  }
    printf("\ni:%d\n",i);
  
    //   extern void *malloc (size_t __size)
    //   extern void *realloc (void *__ptr, size_t __size)
    int *ahfa=malloc(sizeof(int)*5);
    if(!ahfa){
      printf("allocation failed\n");
    }else{
      printf("allocation successful\n");
    }
    
    int *afafa=realloc(NULL,sizeof(int)*5);
     //   extern void *calloc (size_t __nmemb, size_t __size)
    if(!afafa){
      printf("allocation failed\n");
    }else{
      printf("allocation successful\n");      
    }
    printf("ahfa:\n");
    for(int i=0;i<5;i++){
      printf("%p\n",(ahfa+i));
    }
    printf("\nafafa:\n");
    for(int i=0;i<5;i++){
      printf("%p\n",(afafa+i));
    }			
    FILE*fp;
    fp=fopen("data.txt","r");
    
char*fff=readline(fp);
 print(fff);
 fff=readline(fp);
 printf(fff);
 fclose(fp);
 free(fff);
    return 0;
}

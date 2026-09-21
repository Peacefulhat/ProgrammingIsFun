#include<stdio.h>
#include<string.h>// not complete.
#define MAXLINES 1000
int getLine(char*line,int size){
  int c,i;
  for( i=0;i<size-1&&(c=getchar())!=EOF&&c!='\n';i++){
  line[i]=c;
  }
  if(c=='\n'){
    line[i]='\n';
    ++i;
  }
  line[i]='\0';
  return i;
}

int main(int argc,char*argv[]){
  char buffer[MAXLINES];
  long linenumber=0;
  int c,except=0,number=0,found=0;
  while(--argc>0&&(*++argv)[0]=='-'){
    while((c=*++argv[0])){
      switch(c){
        case 'x':
        except=1;
        break;
        case 'n':
        except=1;
        break;
        default:
          printf("find : illegal optionc %c",c);
          argc=0;
        found=-1;
        break;
      }
    }
  }
  if(argc!=1){
    printf("usage: find -x -n pattern\n");
  }else{
    while(getLine(buffer,MAXLINES)>0){
      linenumber++;
      if((strstr(buffer,*argv)!=NULL)!=except){
          printf("%ld:",linenumber);
          printf("%s",buffer);
        found++;
      }
      }
    }if (found>0) {
 printf("true");   }
 // printf("%d",found);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
// TODO:: learn more about serialization of data in binary format.
// file:
/*The FILE* Data Type:
When we do any kind of I/O in C, we do so through a piece of data that you get in the form of a FILE* type. This FILE* holds all the information needed to communicate with the I/O subsystem about which file you have open, where you are in the file, and so on.*/

/*FILE* name 	Description
stdin: 	Standard Input, generally the keyboard by default.
stdout: Standard Output, generally the screen by default.
stderr:	Standard Error, generally the screen by default, as well.
 */

#define MAX_BUFFER_SIZE  1024
#define path "./file_c/textfile.txt"
#define opath "./file_c/output.txt"
#define bpath "./file_c/mybinary.bin"
#define epath "./file_c/e"
#define spath "./file_c/s.bin"

typedef struct{
  const char*s;
  float pos;
  int c;
}custom;



void swrite(){// writing a structure
  FILE* fp;
  fp = fopen(spath,"wb");
  int times=5;
  for(int i=0;i<5;i++){
  custom st;
  st.s="random";
  st.pos=23.3;
  st.c=123;
  fwrite(&st,sizeof(st),1,fp); // writing one sturct at a time .
  }
  fclose(fp);
}

void sread(){// reading a sturcture 
  FILE*fp;
  fp=fopen(spath,"rb");
  custom st;
  int times=5;
  for(int i=0;i<5;i++){
  fread(&st,sizeof(st),5,fp);// reading one struct form file
  printf("file pointer: %p\n",fp);
  printf("%s ",st.s);
  printf("%f ",st.pos);
  printf("%d \n",st.c);
  }
  fclose(fp);
}

void ewrite(){
    FILE *fp;
    unsigned short int v = 0x1234; // two bytes 0x12 0x34
    fp = fopen(epath, "wb");
    if (fp != NULL) {
        fwrite(&v, sizeof(v), 1, fp);
        fclose(fp);
    }
}
void eread(){
    FILE *fp;
    unsigned short int v; // two bytes 0x12 0x34
    fp = fopen(epath, "rb");
    
         while (fread(&v, sizeof(v), 1, fp) > 0) {
            printf("%x\n", v);
        }
        fclose(fp);
 }


void writefile(){
  FILE*fp;
  fp=fopen(opath,"w");
  fputc('B',fp);
  fputc('\n',fp);
  fprintf(fp,"x=%d\n",32);
  fputs("Hello,World!\n",fp);
  fclose(fp);
}

void readfile(){
FILE* fp=NULL;
char buf[MAX_BUFFER_SIZE];
fp=fopen(path,"r");

 if(!fp){
   printf("File not open");
   exit(1);
}
 int i=0,c;
 // fgetc(FILE*fp) reads a character from file everytime its called . and it also remember the file pointer state.if it reaches the endoffile it returns EOF macro value to tell its endoffile.
   while ((c = fgetc(fp)) != EOF){
    if(c!='\n'){
      buf[i++]=(char)c;
      continue;
    }
    buf[i++]='\n';
    buf[i]='\0';
    printf("%s",buf);
    i=0;
  }
  fclose(fp);
  printf("\n");
 }


void readfile2(){
  FILE* fp=NULL;
char buf[MAX_BUFFER_SIZE];
fp=fopen(opath,"r");
 // fgets(char *buffer,int buffersize,FILE*fp) and returns null if it reaches end of file. reads a line at time and put it into the buffer. 
 while (fgets(buf,MAX_BUFFER_SIZE,fp) != NULL){
    printf("%s",buf);
  }
  fclose(fp);
  printf("\n");
}

void format(){
 FILE *fp;
    char name[1024];  // Big enough for any line this program will encounter
    float length;
    int mass;

    fp = fopen(path, "r");

    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
        printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

    fclose(fp);
}

void wbinary(){
  FILE*fp;
  int byte[7]={1,2,3,4,5,6,7};
  fp=fopen(bpath,"wb");
  fwrite(byte,sizeof(int),7,fp);
  fclose(fp);
}




void rbinary(){
   FILE*fp;
   int byte;
   fp=fopen(bpath,"rb");// rb read bianry
   int f=0;
   while((f=(fread(&byte,sizeof(int),1,fp))>0)){
     printf("%d",f);
     /* if(f!=1){ */
     /* printf("%d,",byte); */
     /* continue; */
     /* } */
     printf("%d ",byte);
   }

  fclose(fp);
}
int main(){
  swrite();
  sread();
  // Reading Text file
  //FILE* fp;
  //fp=fopen("textfile.txt","r");
  //printf("%p\n",fp);
  
  //  readfile();
  //  writefile();
  //  readfile2();
  //End of File: EOF
  //format();
  // wbinary();
  //rbinary();
  //  ewrite();
  //  eread();
  /*There is a special character defined as a macro: EOF. This is what fgetc() will return when the end of the file has been reached and you’ve attempted to read another character.*/
  return 0;
}



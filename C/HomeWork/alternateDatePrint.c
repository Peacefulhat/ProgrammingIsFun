#include<stdio.h>
#include<stdbool.h>
#define WIDTH 14 //14;
#define MHEIGHT 12 //0 to 11
#define MWIDTH 4
#define uint unsigned int

typedef struct{
char month[MWIDTH];
uint year;
uint day;
}date; 


void parse(date *s,char*buf){
    s->year=0;
    uint index=0;
    s->day=((uint)buf[index]-48)*10+((uint)buf[index+1]-48);
    index=3;
    int j=0;
    for(;buf[index]!='-';index++){
        s->month[j]=buf[index];
        j++;
    }
    index++;
    s->month[j]='\0'; 
    for(;buf[index]!='\0';index++){
        s->year=s->year*10+((uint)buf[index]-48);
    } 
}
bool strc(char *str1,char*str2){
    bool val=1;
    for(uint i=0;(str1[i]!='\0');i++){
       if(str1[i]!=str2[i]){
       val=0;
       break; 
       } 
    }
    return val;
}

int main(){ 
    date s1;
    char month[MHEIGHT][MWIDTH]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    char buffer[WIDTH];
    printf("date:");
    scanf("%s",buffer);
    parse(&s1,buffer);
    int index=-1;
    for(int i=0;i<MHEIGHT;i++){
    if(strc(s1.month,month[i])){
     index=i;
     break;
    }
    }
 printf("times: ");
 uint n;
 scanf("%d",&n);
bool y=0;
 for(int i=1;i<=n;i++){
index+=2;
 if(index>11){
    s1.year++;
    index=index%12;
 }
 printf("%d-%s-%d\n",s1.day,month[index],s1.year);
 }
    return 0;
}
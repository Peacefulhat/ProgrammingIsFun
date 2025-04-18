#include<stdio.h>
#define MAX 23
int Getline(char str[]){
    int i;
    int c;
    for(i=0;i<MAX-1&&(c=getchar())!=EOF&&c!='\n';i++)
    {
        str[i]=c;
    }
    str[i]='\0';
    return i;
}
void squeeze(char str[],int c){
    int j=0;
    for(int i=0;str[i]='\0';i++){
        if(c!=str[i]){
            str[j]=str[i];
            j++;
        }
    }
    str[j]='\0';
}
void strCat(char first[],char second[]){
    int i=0,j=0;
    while(first[i]!='\0'){
        i++;
    }
    if(i==MAX){
        return ;
    }
    //while(first[i++]=senond[j++]!='\0');
    while(second[j]!='\0'){
        first[i++]=second[j++];
    }
}
int main(){
    char str[MAX]={'A','\0'};
    char str1[]="abhfadfadfadfc";
    strCat(str,str1);
    printf("%s",str);
}

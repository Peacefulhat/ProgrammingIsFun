// extract string program
#include<stdio.h>

int xstrlen(char str[]){
    int i=0;
    while(str[i]!='\0'){i++;}
    return i;
}

void xstrrev(char str[],int start,int end){
    while(start<=end){
    char temp=str[start];
    str[start] = str[end];
    str[end]=temp; 
    start++;
    end--;
    }
}
void xstrcat(char str[],char str2[]){
int size=xstrlen(str)-1;
int i=0;
while(str2[i]!='\0'){
str[size]=str2[i];
i++;
size++;
}
str[size]='\0';
}

void half(char str[]){
    int length=xstrlen(str);
    int mid=length/2;
    if(length%2==0){
    xstrrev(str,0,mid-1);
    xstrrev(str,mid,length-1);
    }else{
        xstrrev(str,0,mid-1);
        xstrrev(str,mid+1,length-1);
    }


}

int main(){
char str[10];
scanf("%s",str);
half(str);
printf("%s",str);
}

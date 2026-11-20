#include<stdio.h>
static char dayTab[2][13]={
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int dayOfYear(int year,int month,int day){
int i,leap;
leap =year%4==0&&year%100!=0||year%400==0;
for(int i=1;i<month;i++){
    day+=dayTab[leap][i];
  }
return day;
}
// Home work:// add some error checking;
int dayOfYear2(int year, int month,int day){
  if(month>12&&day>31){return 0;}
  if(day<1&&month<1){return 0;}
  int i,leap;
leap =year%4==0&&year%100!=0||year%400==0;
for(int i=1;i<month;i++){
    day+=dayTab[leap][i];
  }
return day;
  
}

/* unable to understand what this function does.
 typedef struct {
  int pmonth;
  int pday;
} md;
md date;
void monthDay(int year,int yearday,int *pmonth, int *pday){
  int i,leap;
  leap=year%4==0&&year%100!=0|| year%400==0;
  for(int i=1;yearday>dayTab[leap][i];i++){
    yearday-=dayTab[leap][i];
    *pmonth=i;
    *pday=yearday;
  }
  printf("%d %d",*pmonth,*pday);
}*/
// initialization of pointer arrays;
char *monthName(int monthIndex){ // index =1 to 12;
  static char*name[]={
      "Illegal month","January","February","March","April","May",
      "June","July","August","September","October","November","December"
    };
  return monthIndex<1||monthIndex>12?name[0]:name[monthIndex];
  }

// pointers and multi-dimensional arrays.
// Homework: dayOfYear with pointers instead;
  int dayOfYear3(int year,int month, int day){
  int leap;
  //char *ptr[]; or int (*ptr)[13] are ways in which you define arrays.
  leap=year%4==0&&year%100!=0||year%400==0;
  for(int i=1;i<month;i++){
  day+=*(*(dayTab+leap)+i); 
  }  
  return day;
}
int main(){
 /* printf("%s",monthName(2));
  char* someaddress=monthName(3);
  for(int i=0;someaddress[i]!='\0';i++){
    printf("%c ",*(someaddress+i));
  }*/
 printf("%d",dayOfYear3(1988,1,2)); 
  return 0;
}

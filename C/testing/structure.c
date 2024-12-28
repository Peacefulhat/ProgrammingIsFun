#include<stdio.h>
//typedef orignialname another name; use to define allises.
//structure in c syntax;
typedef struct{
float x,y,z;
}point;
// structure and functions.
point pointAddition(point first,point second){
  point temp;
  temp.x=first.x+second.x;
  temp.y=first.y+second.y;
  temp.z=first.z+second.z;
  return temp;
}
// array of structure.
static point particals[3]={
  {1.3,2.3,4.1},{1.4,2.5,5.5},{3.5,2.3,2.5}
};
// pointer to structure;
point* global=particals;
// Self referential structure;
// are structure that points to there own objects.
struct point3d{// 
  float x,y,z;
  struct point*next;
};

int main(){
  // makeing structure objects or variables.
  point temp={0,0,0};
  for(int i=0;i<3;i++){
  temp=pointAddition(*(global+i),particals[i]);
  printf("%f %f %f\n",temp.x,temp.y,temp.z);
  }
  point*somePointer=&temp;
  printf("%f %f %f\n",somePointer->x,(*somePointer).y,somePointer->z); 
  return 0;
}

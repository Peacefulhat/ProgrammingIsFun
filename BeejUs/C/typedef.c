#include<stdio.h>
// typedef
// let us define new name for existing type.
// let us define alias for existing type.

struct animal{
  char* name;
  int leg_count,speed;
};
typedef struct animal animal;

// work with arrays as well.
typedef int five_int[5];
five_int x= {1,2,3,4,5};

typedef struct{ // anonymous structure , have no name
  float x,y;
}point2d;// new name;

point2d origin={.x=0,.y=0};

void print_point(point2d *pt){
  printf("x:%f\n",pt->x);
  printf("y:%f\n",pt->y);
}

point2d temp={.x=23,.y=13};
typedef unsigned int uint;

struct animal my_animal(const char* name,int leg_count,int speed){
  struct animal st;
  st.name=(char*)name;
  st.leg_count=leg_count;
  st.speed=speed;
  return st;
}
void print_animal(animal *st)
{
  printf("Name:%s\n",st->name);
  printf("Leg_Count:%d\n",st->leg_count);
  printf("Speed:%d\n",st->speed);
}
void print(){ printf("Typedef:\n");}

int main(int argc,char** argv){

  print();
  uint a=1;
  printf("%u\n",a);
  animal s=my_animal("cow",4,20);
  print_animal(&s);
  print_point(&origin);
  print_point(&temp);
  return 0;
}

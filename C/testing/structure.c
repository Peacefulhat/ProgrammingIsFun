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
struct sr_point3d{// 
  float x,y,z;
  struct point*next;
};

// structure embedding

typedef struct {
  struct point2d{
    float x;
    float y;
  }position;
  const char* name;
  struct attributes{
    short int strength;
    short int vigor ;
    short int endurence;
    short int dexterity;
    short int faith;
    short int intellegnece;
    }stats;
}Player;

int main(){
  // makeing structure objects or variables.
  point p ={
    .y=4.0f,
    .x=3.0f,
    .z=5.0f
  };
  printf("Normal Structure");
  printf("{%f, %f, %f}\n",p.x,p.y,p.z);
  printf("Embeded structure\n");
  
  Player player_one;
  player_one.position.x = 23;
  player_one.position.y = 46;
  player_one.name = "Peacefulhat";
  player_one.stats.strength = 10;
  player_one.stats.vigor=10 ;
  player_one.stats.endurence=10;
  player_one.stats.dexterity=10;
  player_one.stats.faith=10;
  player_one.stats.intellegnece=10;
  printf("Player Data ::\n");
  printf("Player Name :: %s\n",player_one.name);
  printf("Player Position :: {x:: %f,y:: %f}\n",player_one.position.x, player_one.position.y);
  printf("Player Attributes :: \n");
  printf("Strength :: %d \n",player_one.stats.strength);
  printf("Vigor :: %d \n",player_one.stats.vigor);
  printf("Endurence :: %d \n",player_one.stats.endurence);
  printf("Dexterity :: %d \n",player_one.stats.dexterity);
  printf("Faith :: %d \n",player_one.stats.faith);
  printf("Intellegnece :: %d \n",player_one.stats.intellegnece);
  return 0;
}

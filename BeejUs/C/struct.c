#include<stdio.h>

// struct:
// userdefined type, potenteially containing multiple types.


// Declaring structs.
// often done at global scope.
  struct car{
   const char *name;
    float price;
    int speed;
  };

void details(struct car c){
  printf("Name:%s\n",c.name);
  printf("Price:%f\n",c.price);
  printf("Speed:%d\n",c.speed);
  printf("\n");
}

void pdetails(struct car* c){
  printf("Name:%s\n",c->name);
  printf("Price:%f\n",(*c).price);// with this method or with arrow operator.
  printf("Speed:%d\n",c->speed);
  printf("\n");
} 

int main(){
  struct car c;
  // accessing the members using (.) operator
  c.name="BMW";
  c.price=332.23;
  c.speed=100;

  details(c);
  // structure initializers
  struct car saturn = {"Saturn SL/2", 16000.99, 175};
  details(saturn);
  
  struct car saturn2 = {
    .speed=175,
    .name="Saturn SL/3",
    .price=2342.2234
  };

  details(saturn2);
  
  // passing structure to function
  //  So when accessing fields, when do we use dot and when do we use arrow?

  //If you have a struct, use dot (.).
  //If you have a pointer to a struct, use arrow (->).

  details(c);
  pdetails(&saturn);

  // copying structs.

  struct car b;
  b=c;
  details(b);
  return 0;
}

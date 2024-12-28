#include<stdio.h>
int sum(int a, int b){
  return a+b;
}

void array_to_function(int*ptr,int size){
  for(int i=0;i<size;i++){
    ptr[i]=ptr[i]+i;
  }
}

// passing multidimensional arrays to funcitons
//The story changes a little when we’re talking about multidimensional arrays. C needs to know all the dimensions (except the first one) so it has enough information to know where in memory to look to find a value.

//void print_2D_array(int a[2][3])
//void print_2D_array(int a[][3])
// both are equivalent;
void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}

#define MAX_COUNT 5
void foo(int *ptr){
  printf("passing ann>rray to function:\n");

  printf("size of array:%d\n",sizeof(ptr));
  printf("size of int:%d\n",sizeof(int));
  printf("number of elements:%d\n",sizeof(ptr)/sizeof(int));
}
int main(){
  char arr[23];// size = 23 bytes char=1byte
  int i;
  float f[4];
  f[0]=3.14159;
  f[1]=1.41421;
  f[2]=1.61803;
  f[3]=2.71828;
  for(int i=0;i<4;i++){
    printf("fmembers:%f\n",f[i]);
  }
  printf("float:%d\n",sizeof(float));
  printf("float array:%d\n",sizeof(f));
  int x[12];
  foo(x);// ptr =&x[0], maps to name of array,x ptr=x
  printf("%d\n",sizeof(double[48]));//48*8
  // Array initlizer
  int bin[5]={0}; // all elements zero
  
  printf("sizeof bin: %d",sizeof(bin));
  for(int i=0;i<5;i++){
    printf("mm:%d\n",bin[i]);
  }
  // explicit index initilizaiton in inilizer list
  int s[5]={1,23,[2]=32,5,52};
  for(int i=0;i<5;i++){
    printf("explicit initliaztion in initilizer list %d,i:%d\n",s[i],i);
  }
  int sudo[10] = {0, 11, 22, [5]=55, 66, 77};//Which means, “Make the first element zero, and then automatically make the rest zero, as well.”
  //Note:You can set specific array elements in the initializer, as well, by specifying an index for the value! When you do this, C will happily keep initializing subsequent values for you until the initializer runs out, filling everything else with 0.
  for(int i=0;i<10;i++){
    printf("[sm:%d,i:%d]\n",sudo[i],i);
  }
  //[2] starting from to assgin these values.

  int afa[MAX_COUNT]={[MAX_COUNT-3]=3,2,1};
  for(int i=0;i<MAX_COUNT;i++){
    printf("[afa :%d,i: %d]\n",afa[i],i);
  }
  int dafa[]={1,23,[4]=3,1};
    for(int i=0;i<7;i++){
      if(i==6){printf("outofboundvalue:\n");}
    printf("[dafa:%d,i:%d]\n",dafa[i],i);
  }

    // multidimensional array
    int fafa[10];
    int fda[2][7];
    int dsf[4][5][6];
    for(int i=0;i<2;i++){
      for(int j=0;j<7;j++){
	printf("{member:%d,[i:%d,j:%d]}\n",fda[i][j],i,j);
      }
    }
    // explit array
    int mat[3][3]={[0][0]=1,[1][1]=1,[2][2]=1};

      for(int i=0;i<3;i++){
	printf("Row:%d |{",i+1);
      for(int j=0;j<3;j++){
	if(j!=3-1){
	printf("%d,",mat[i][j]);
	continue;
	}
	printf("%d",mat[i][j]);
	}
      	printf("}|\n");
      }

      // pointers and arrays
      int pass[5]={31,24,27,71,9};
      int *p;
	p=&pass[0];// p points to first element
	printf("%d",*p);
	p=pass;// both are same thing
	// array name is like points to first elements address.
      printf("%d\n",*p);

 // passing to array to function
 // void times2(int *a, int len)
 // void times3(int a[], int len)
 // void times4(int a[5], int len)
 // all this array passing as parameter are same.
      array_to_function(pass,5);
      for(int i=0;i<5;i++){
	printf("%d ",pass[i]);
       }
      printf("\n");

      int suh[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
      int (*fa)[3];// pointer to array of 3 integers
      fa=suh;
      printf("%p\n",fa);
      int *pt=&suh[0][0];
       printf("%p\n",pt);
       printf("%p\n",(fa)[0]);
       for(int i=0;i<2*3;i++){
       printf("value:%d\n",(*fa)[i]);
       }       
      print_2D_array(suh);
    return 0;
}

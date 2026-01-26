#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int Sum = 0; //  this vairable is shared among the threads;
void *Runner(void *Param); // therad call this funcion;


int main(int argc , char *argv[])
{
    pthread_t MyThread; // thread vairable.
    pthread_attr_t Attr; // set of thread attribute.
    
    if(argc != 2)
    {
        fprintf(stderr, "usage : main <interger value> \n");
        return -1;
    }
    
    if(atoi(argv[1]) < 0)
    {
        fprintf(stderr, "%d must be >=0\n", atoi(argv[1]));
        return -1;
    }
    
    pthread_attr_init(&Attr);
    pthread_create(&MyThread, &Attr, Runner, argv[1]);
    pthread_join(MyThread, NULL);
    printf("%d", Sum);
    return 0;
}

void *Runner(void* Param)
{
    int Bound = atoi(Param);
    for(int i = 1; i <= Bound; ++i)
    {
        Sum+=i;
    }
}

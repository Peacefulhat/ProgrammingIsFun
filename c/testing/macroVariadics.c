#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// imitating default arguments for function


typedef struct {
    size_t count;
    size_t capacity;
    int* items;
}da;

void print(const da*e )
{
    printf("%ld",e->count);
    printf("Dynamic Array :: {");
    for(size_t i = 0; i < e->count; ++i)
    {
        if((i - (e->count-1)) == 0){
            printf("%d",e->items[i]);
            break;
        }
        printf("%d,",e->items[i]);
        
    }
    printf("}\n");
    
}
//consider:: for testing dest size alwayas greater than src
// it will erase the thing , it hard copy
void acpy(int *dest, int*src, size_t size_src){
    for(size_t i = 0; i < size_src; ++i){
        dest[i]=src[i];
        }
}

void cpy(da *dest, da src){
    src.items = malloc( sizeof(int) * src.count );
    memset(src.items, 0,src.count);
    acpy(dest->items, src.items, src.count);
}

#define da_init(...) (da){__VA_ARGS__}
#define da_cpy(dest,...) cpy((dest),(da){__VA_ARGS__})

int main(){
    //#define nob_cmd_run(cmd, ...) nob_cmd_run_opt((cmd), (Nob_Cmd_Opt){__VA_ARGS__})
    da dest;
    da_init(dest.count=4,dest.capacity=4);
    dest.items = malloc( sizeof(int) * dest.count );
    dest.items[0] = 3;
    dest.items[1] = 7;
    dest.items[2] = 9;
    dest.items[3] = 11;
    printf("count :: %ld, capacity :: %ld\n",dest.count,dest.capacity);
    print(&dest);
    da_cpy(&dest, .count=3,.capacity=3);
    printf("count :: %ld, capacity :: %ld\n",dest.count,dest.capacity);
    print(&dest);


    return 0;
    
}

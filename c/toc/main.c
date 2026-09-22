#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    bool v[4] = {};
    const char* string="aa*bb";
    const char* usrdata = "xhab";
    int count = strlen(string);
    for(int i=0; i< 4; i++) {
        if(string[i]==usrdata[i]) {
            v[i] = 1;
        }
    }
    int state_count = 0;
    for(int i = 0; i< 4; i++){
        if(v[i] == 1){
            state_count++;
        }else
        {
            break;
        }
    }
    if(state_count == count ){
        printf("dfa valid");
    }else{
        printf("dfa not-valid");
    }
    
    return(0);
}

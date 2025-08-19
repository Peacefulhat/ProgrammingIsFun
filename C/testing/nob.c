#define NOB_IMPLEMENTATION
#include "nob.h"
#define MAX_FILE_NAME 100

char* trim_end(char**argv, char *buffer){
    
    unsigned short i=0;
    
    while(argv[1][i]!='.'){
        buffer[i++]=argv[1][i];        
    }
    
    buffer[i]='\0';

    return buffer;

}

int main(int argc, char** argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};
    char out_filename[MAX_FILE_NAME];
    
    nob_cmd_append(&cmd, "gcc" , "-Wall", "-Wextra", "-o",trim_end(argv,out_filename),argv[1]);
    
    
    
    if(!nob_cmd_run_sync(cmd)) return 1;
    
    return 0;
}


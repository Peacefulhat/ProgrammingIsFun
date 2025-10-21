#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define SOCKET_PATH "/home/peacefulhat/ProgrammingISFun/C/la_socket/test_socket"

int main(void)
{

    struct sockaddr_un soc;
    memset(&soc, 0, sizeof(struct sockaddr_un));
    soc.sun_family = AF_UNIX;
    strncpy(soc.sun_path,
    SOCKET_PATH,// absoulute path needed
    sizeof(soc.sun_path) -1);
    soc.sun_path[sizeof(soc.sun_path)-1] = '\0';// null termination is needed
    int net_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    
    if(net_fd == -1){
        perror("socket");
    }
    
    if(connect(net_fd ,(struct sockaddr*)&soc, sizeof(soc)) == -1){
        perror("connect");
        return 1;
    }

    char buffer[16] = {0};
    for(int i = 0; i< 5; i++){
    if(read(net_fd, buffer,16) == -1)
    {
        perror("read");
        return 1;
    }
    printf("%s\n", buffer);
    fflush(stdout);
    memset(buffer, 0, 16);
    }
    return 0;

}

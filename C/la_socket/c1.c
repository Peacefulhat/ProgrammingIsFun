/*
 Simple IPC Using Socket

socket() it way through which process can with one another
bind() binds the socket to some path
connect() connect two process.
accept() accepts the connection form another process
write() write data to a fd (client process fd which is returned by accept() function)
read() read data from fd(on clinet side ) and write to into some buffer

*/

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
    unlink(SOCKET_PATH); // unlinks if socket exits
    int net_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    
    if(net_fd == -1){
        perror("socket");
        return 1;
    }
    if(bind(net_fd ,(struct sockaddr*)&soc, sizeof(soc)) == -1){
        perror("bind");
        return 1;
    }
    if(listen(net_fd,1) == -1){
        perror("listen");
        return 1;
    }

    socklen_t soc_len = sizeof(soc);
    int client_fd = accept(net_fd, (struct sockaddr*)&soc, &soc_len);
    if(client_fd == -1){
        perror("accept");
        return 1;
    }
    printf("Client connected!\n");
    fflush(stdout);
    char buffer[] = "Hello,Im Server!";
    for (int i = 0 ; i<5; i++){
    if(write (client_fd, buffer, strlen(buffer)) == -1){
        perror("write");
        return 1;
    }
    }

    return 0;

}

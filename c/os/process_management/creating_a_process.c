// fork: creates a new process by duplicating the calling process.
    // The new process is referred to as a child process.
    // The calling process is referred to as the parent process.
    // both have different memory space, have duplicate content.
    
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    
    pid_t ChildProcessID = fork(); // child has its own unique id
    // at this point there are two process one is child and other is parent
    // in parent process(this process), we get childs process id
    // in child we get 0, note there are two process. with same data
    // and then we check in child process if the process id is Zero or not if it is then we execute the
    // statements inside it.
    // and return to parent process.
    // parent will wait until its child finished executing.
    
    pid_t ParentProcessID = getpid();

    if(ChildProcessID < 0) {
        printf("Fork Failed");
        return (1);
    } else if(ChildProcessID == 0) {
        printf("Created Child Process %d", ChildProcessID);
        execlp("/bin/ls", "ls", NULL);
    } else {

        wait(NULL); // halts here until, its child done executing.
        printf("Child Process Completed");
    }
    return(0);
}

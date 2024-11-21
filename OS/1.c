// WAP to implement the process system calls [fork(), exec(), create_process, terminate_process]

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid<0){
        perror("Fork Failed");
        exit(1);
    }
    else if (pid==0){
        printf("Child Process with pid %d\n", getpid());
        execlp("/bin/ls", "ls", NULL);
    }
    else{
        wait(NULL);
        printf("Child Complete");
    }
}
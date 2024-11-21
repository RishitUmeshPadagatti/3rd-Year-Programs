// WAP which demonstrates interprocess communication between a reader and a writer process
// Use mkfifo, open, read, write and close APIs in your program

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 1024

void reader(){
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(FIFO_NAME, O_RDONLY);

    if (fd == -1){
        perror("Error opening FIFO for reading");
        exit(1);
    }
    read(fd, buffer, BUFFER_SIZE);
    printf("Reader: Received message: %s\n", buffer);
    close(fd);
}

void writer(){
    int fd;
    char message[]="Hi";

    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1){
        perror("Error open FIFO for writing");
        exit(1);
    }
    write(fd, message, sizeof(message)+1);

    close(fd);
}

int main(){
    pid_t pid;
    if (mkfifo(FIFO_NAME, 0666) == -1){
        perror("Error Creating FIFO");
        exit(1);
    }
    pid = fork();
    if (pid == -1){
        perror("Fork Failed");
        exit(1);
    }
    else if (pid == 0){
        reader();
    }
    else {
        writer();
        wait(NULL);
    }
    unlink(FIFO_NAME);

    return 0;
}
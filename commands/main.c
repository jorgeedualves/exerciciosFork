#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main (int argc, char* argv[])

{
    int pid;

    pid = fork();
    if(fork() == -1)
        return (1);
    if(pid == 0)
    {
        // child process
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
        printf("isso não deve imprimir no terminal!");
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("Success!\n");
        printf("Algum pós processo de dados aqui!\n");
    }
    return (0);
}


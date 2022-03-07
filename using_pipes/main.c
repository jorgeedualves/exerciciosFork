#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main (int argc, char* argv[])

{
    int pipe1[2];  // C -> P
    int pipe2[2];  // P -> C
    int pid;
    
    if(pipe(pipe1) == -1)
        return (1);
    if(pipe(pipe2) == -1)
        return (1);
     pid = fork();
    if (pid == -1)
        return (2);
    if (pid == 0)
    {
        // child process
        // Quando um das extremidade do PIPE aguarda que a outra seja executada para prosseguir,
        // E o mesmo PIPE não pode ler no mesmo processo o que ele mesmo escreveu:  
        close(pipe1[0]);    // fecha o fd de leitura do PIPE1
        close(pipe2[1]);    // fecha o fd de escrita do PIPE2
        
        int x;
        
        if(read(pipe2[0], &x, sizeof(x)) == -1)
            return (3);
        printf("[FILHO] - Recebido %d\n", x);
        x *= 4;
        if(write(pipe1[1], &x, sizeof(x)) == -1)
            return (4);
        printf("[FILHO] - Escrevi %d\n", x);
        close(pipe1[1]);
        close(pipe2[0]);
    }
    else
    {
        // Parent process
        close(pipe1[1]);
        close(pipe2[0]);
        srand(time(NULL));
        int y = rand() % 10;
        if (write(pipe2[1], &y, sizeof(y)) == -1)
            return (5);
        printf("[PAI] - Escrevi:%d\n", y);
        if (read(pipe1[0], &y, sizeof(y)) == -1)
            return (6);
        printf("[PAI] - Resultado é %d\n", y);
        close(pipe1[0]);
        close(pipe2[1]);
        wait(NULL);
    }
    return (0);
}
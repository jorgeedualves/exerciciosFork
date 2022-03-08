#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    int pid;

    pid = fork();
    if(fork() == -1)
        return (1);
    if(pid == 0)
    {
        // child process
		int file;
		int err;
				
		file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		printf("O FD para PingResults: %d\n", file);
		dup2(file, STDOUT_FILENO);
		close(file);

        err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err = -1)
	        printf("não foi possível encontrar o programa para executar");
				return (2);
    }
    else
    {
       // Parent process
		int wstatus;
		int statusCode;
        wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
		        printf("Success!\n");
			else
				printf("Falhou com statuscode: %d\n", statusCode);
		}
				printf("Algum pós processo de dados aqui!\n");
    }
    return (0);
}
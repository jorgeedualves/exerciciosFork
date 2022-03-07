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
				int err;
				if (err = -1)
	        printf("Could not find program to exec");
					return (0);
    }
    else
    {
        // Parent process
		int wstatus;
		int statuscode;
        wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			statuscode = WEXITSTATUS(wstatus);
			if (statuscode == 0)
			    printf("Success!\n");
			else
			    printf("Falhou com statuscode: %d\n", statuscode);
		}
				printf("Algum pós processo de dados aqui!\n");
    }
    return (0);
}
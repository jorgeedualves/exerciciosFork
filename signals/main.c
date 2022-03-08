#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main (int argc, char* argv[])
{
  int pid;
	

	pid = fork();
	if(pid == -1)
		return (1);
	if(pid == 0)
	{
		//child process
		while(1)                                // processo fica executando em loop infinito
		{
			printf("Algum texto vai aqui!\n");
			usleep(50000);
		}
	}
	else
	{
		sleep(1);
        printf("Processo PAI: Comando KILL!\n");
		kill(pid, SIGKILL);
		wait(NULL);
	}		
  return (0);
}
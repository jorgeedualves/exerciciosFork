#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	int id;

	id = fork();
	int res;
	printf("Processo atual ID:%d, Pai desse processo: %d\n", getpid(), getppid());

	res = wait(NULL);
	if(res == -1)
		printf("Sem filhos para esperar\n");
	else
		printf("%d execução finalizada\n",res);

	return (0);
}
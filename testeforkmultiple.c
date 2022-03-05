#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main (int argc, char *argv[])
{
	int id1;
	int id2; 

	id1 = fork();
	id2 = fork();
	if(id1 == 0)
	{
		if(id2 == 0)
			printf("Estamos no processo Y\n");
		else
			printf("Estamos no processo X\n");
	}
	else
	{
		if(id2 == 0)
			printf("Estamos no processo Z\n");
		else
			printf("Estamos no processo PAI\n");
	}
	while(wait(NULL) != -1 || errno != ECHILD)
		printf("Esperando que o filho termine\n");
	return (0);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main (int argc, char *argv[])
{
	int arr[] = { 1, 2, 3, 4, 1, 2};
	int arrSize;
	int fd[2];
	int id;
	int start;
	int end;
	int sum;
    int sumFromChild;
	int i; 
	
    sum = 0;
	arrSize = sizeof(arr) / sizeof(int);  // nos dará o número de elementos
	if(pipe(fd) == -1)
	{
		printf("Ocorreu um erro ao abrir o Pipe\n");
		return(1);
	}
	id = fork();
	if(id == -1)
	{
		printf("Ocorreu um erro com o fork\n");
		return(2);
	}
	if (id == 0)
	{
		start = 0; 
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	i = start;
	while(i < end)
	{
		sum += arr[i];
		i++;
	}
	printf("Resultado parcial a soma: %d\n", sum); 
	if(id == 0)
    {
        close(fd[0]);
        if(write(fd[1], &sum, sizeof(sum)) == -1)
            return(3);
        close(fd[1]);
    }
    else
    {
        int sumFromChild;
        close(fd[1]);
        if(read(fd[0], &sumFromChild, sizeof(sumFromChild) == -1))
            return(4);
        close(fd[0]);

        int totalSum = sum + sumFromChild;
        printf("Soma Total é: %d\n", totalSum);
        wait(NULL);
    }
	return (0);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main (int argc, char *argv[])
{
	int fd;
	int x;
	
	if (mkfifo("myfifo1", 0777) == -1); //Paramentros(nome arquivo, bits de permissão)
	{
		if (errno != EEXIST)      // Se FIFO Não existe
        {
            printf("Não foi possivel criar o arquivo FIFO\n");
			return(1);
        }
    }
	printf("Opening...\n");
	fd = open("myfifo1", O_WRONLY); // O_WRONLY transforma "myfifo1" em um descritor de arquivo
	printf("Opened\n");
	x = 97;
	if (write(fd,&x, sizeof(x)) == -1)
		return(2);
	printf("Writen\n");
	close(fd);
	printf("Closed...\n"); 
	return (0);
}
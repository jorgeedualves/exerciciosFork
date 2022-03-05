#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main (int argc, char **argv[])
{
    int arr[5];
    srand (time(NULL));
    int i;
    int fd;

    i = 0;
    while(i++ < 5)
    {
        arr[i] = rand() % 10;
        printf("Gerado %d\n", arr[i]);
    }
        
    fd = open("sum", O_WRONLY);
    if (fd == -1)
        return 1;
    i = 0;
    while (i++ < 5)
    {
        if(write(fd, &arr[i], sizeof(int) * 5) == -1)
            return (2);
    }
    close(fd);
    return(0);
}
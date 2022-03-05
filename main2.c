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
    int fd;
    int i;
    int sum;

    i = 0;
    sum = 0;
    fd = open("sum", O_RDONLY);
    if(fd == -1)
        return (1);
    while(i++ < 5)
    {
        if(read(fd, &arr[i], sizeof(int)) == -1)
            return (2);
        printf("recebido %d\n", arr[i]);
    }
    close(fd);
    i = 0;
    while(i++ < 5)
        sum += arr[i];
    printf("Resultado é %d\n", sum);
    return(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[], char *envp[])
{
    char *arr[] = {"ping", "google.com", NULL};
    char *env[] = {"TEST=enviroment variable", NULL};

    excecl("\\caminho, argumento, google.com", NULL);
    
    execlp("ping", "ping", "google.com", NULL);
    
    execvp("ping", arr);

    execvpe("ping", arr, env);

    return (0);
}
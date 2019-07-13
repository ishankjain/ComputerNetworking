// parent.c: the parent program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
    int i = 0;
    long sum;
    int pid;
    int status, ret;

    printf ("Parent: Hello, World!\n");

    pid = fork ();

    if (pid == 0) {

        // I am the child

        execvp ("./child", NULL);
    }

    // I am the parent

    printf ("Parent: Waiting for Child to complete.\n");

    if ((ret = waitpid (pid, &status, 0)) == -1)
         printf ("parent:error\n");

    if (ret == pid)
        printf ("Parent: Child process waited for.\n");
    printf("%d \n",getpid());
    printf("%d \n",getppid());    
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const argv[])   /*  main() */
{
    pid_t child_pid;
    int counter = 2;

    printf("Counter = %d\n", counter);

    child_pid = fork();
    if (child_pid >= 0) {
        if (0 == child_pid) {      
	        sleep(1);
            printf("Child PID is: %d, my parent PID is: %d\n", getpid(), getppid());
        } else {                    
            printf("Parent PID is: %d\n", getpid());
        }
    } else {
        printf("fork() unsuccessfully\n");      
    }

    return 0;
}

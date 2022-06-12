#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main()
{
	pid_t child;
	child = fork();
	if(child == 0) {
		while(1) {
			printf("Pid child: %d and Pid Parent : %d\n", getpid(), getppid());
			sleep(1);
		}
	} else if(child > 0) {
		printf("Pid child: %d and Pid Parent : %d\n", getpid(), getppid());
	}
	return 0;
}

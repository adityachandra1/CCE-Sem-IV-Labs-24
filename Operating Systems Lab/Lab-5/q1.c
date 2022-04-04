#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	pid_t fork_return=fork();

	if(fork_return==0)
		printf("This is child process: %d\n",getpid());
	else if(fork_return>0)
		printf("Parent process: %d\n",getpid());

	return 0;
}

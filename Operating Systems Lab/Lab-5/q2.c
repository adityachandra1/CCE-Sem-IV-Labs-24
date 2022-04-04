#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>

int main(int argc, char **argv)
{

	pid_t child = fork();
	int i, j;
	pid_t *status;


	if(child == 0)
	{
		printf("Child process\n");
		printf("Sorted strings: ");
		for(i = 1; i < argc - 1; i++)
		{
			for(j = i + 1; j < argc; j++)
			{
				if(strcmp(argv[i], argv[j]) > 0)
				{
					char *temp = argv[i];
					argv[i] = argv[j];
					argv[j] = temp;
				}
			}
		}
		
		for(i = 1; i < argc; i++){
			printf("%s ", argv[i]);
		}
	}

	else if(child > 0)
	{
		wait(status);
		printf("\nParent process\n");
		printf("Unsorted strings: ");
		for(i = 0; i < argc; i++){
			printf("%s ", argv[i]);
		}
		printf("\n");
	}

	else
	{
		printf("Fork failed.");
	}

	return 0;
}

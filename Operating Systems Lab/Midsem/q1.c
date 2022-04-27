#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char **argv){
	pid_t fork_return = fork();
	if(fork_return == 0){
		printf("child\n");
		printf("Size: %ld\n", (sizeof(argv[1])/sizeof(char)));
	} else if (fork_return > 0){
		printf("Parent\n");
		int count = 0 ;
		long int n = (sizeof(argv[1])/sizeof(char));
		for(int i = 0; i < n; i++){
			if(argv[1][i] == 'a' || argv[1][i] == 'e' ||argv[1][i] == 'i' ||argv[1][i] == 'o' ||argv[1][i] == 'u'){
				printf("%c\n", argv[1][i]);
				count++;
			}
		}
		
		printf("Vowel_Count:  %d\n", count);
	}
	return 0;
}

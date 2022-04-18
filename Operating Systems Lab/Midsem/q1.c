#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char **argv){
	pid_t fork_return = fork();
	if(fork_return == 0){
		printf("child\n");
		printf("Size: %ld\n", (sizeof(argv[0])/sizeof(char)));
	} else if (fork_return > 0){
		printf("Parent\n");
		int count = 0 ;
		long int n = (sizeof(argv[0])/sizeof(char));
		for(int i = 0; i < n; i++){
			if(argv[0][i] == 'a' || argv[0][i] == 'e' ||argv[0][i] == 'i' ||argv[0][i] == 'o' ||argv[0][i] == 'u'){
				printf("%c\n", argv[0][i]);
				count++;
			}
		}
		
		printf("Vowel_Count:  %d\n", count);
	}
	return 0;
}

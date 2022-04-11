#include <stdio.h> 
#include <pthread.h> 

int glob_data = 5 ;
void *inputThread(void *p) 
{ printf ("input here. Global data was %d.\n", glob_data) ; 
	glob_data = 15 ; 
printf ("input Again. Global data is now %d.\n", glob_data) ; 
}

int main ( ) 
{ 
  pthread_t input; 
  pthread_create (&input, NULL, inputThread, NULL) ; 
  printf ("Main Process here. Global data = %d\n", glob_data) ;
  pthread_join (input, NULL) ; 
  printf ("End of program. Global data = %d\n", glob_data) ;
}
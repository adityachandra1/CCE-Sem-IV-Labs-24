#include <stdio.h> 
#include <pthread.h>
#include<unistd.h>

void *takeInput(void *p) 
{ 
printf ("Thread ID is ---> %d\n", getpid( )); 
}

int main ( ) 
{ 
  pthread_t input ; 
  pthread_create (&input, NULL, takeInput, NULL) ; 
  printf ("Parent ID is ---> %d\n", getpid( )) ; 
  pthread_create (&input, NULL, takeInput, NULL) ; 
  pthread_create (&input, NULL, takeInput, NULL) ; 
  pthread_join (input, NULL) ; 
  printf ("No more input Thread!\n") ;
}

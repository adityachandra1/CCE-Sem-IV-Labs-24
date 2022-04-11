#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared=1; //shared variable
int main()
 {
 pthread_t thread1, thread2;
 pthread_create(&thread1, NULL, fun1, NULL);
 pthread_create(&thread2, NULL, fun2, NULL);
 pthread_join(thread1, NULL);
 pthread_join(thread2,NULL);
 printf("Final value of shared is %d\n",shared); //prints the last updated value of shared variable
 }
void *fun1()
{
    int x;
    x=shared;	//thread one reads value of shared variable
    printf("Thread1 reads the value of shared variable as %d\n",x);
    x++;  	//thread one increments its value
    printf("Local updation by Thread1: %d\n",x);
    sleep(1);  	//thread one is preempted by thread 2
    shared=x; 	//thread one updates the value of shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n",shared);
}
void *fun2()
 {
     int y;
     y=shared;	//thread two reads value of shared variable
     printf(" 😎️ Thread2 reads the value as %d\n",y);
     y--;  	//thread two decrements its value
     printf("Local updation by Thread2: %d\n",y);
     sleep(1); 	//thread two is preempted by thread 1
     shared=y; 	//thread one updates the value of shared variable
     printf("Value of shared variable updated by Thread2 is: %d\n",shared);
 }

//Aditya Chandra
//200953032

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define MAXCAPACITY 100

int buff[MAXCAPACITY];
sem_t pmutex,cmutex,empty,full;
int in=1, out=1;
int item=0;
void *produce(void *);
void *consume(void *);
int status=0;
void *produce(void *arg)
{
	sem_wait(&empty);
	item++;
    sem_wait(&pmutex);
    buff[in] = item;
    printf("Produced data %d\n",buff[in]);
    in= in % MAXCAPACITY + 1;
    sem_post(&pmutex);
    sem_post(&full);
    return 0;
}

void *consume(void * arg)
{
   int citem=0;
   sem_wait(&full);
   sem_wait(&cmutex);
   citem = buff[out];
   printf(" Consumed Data = %d\n",buff[out]);
   out= out % MAXCAPACITY + 1;
   sem_post(&cmutex);
   sem_post(&empty);
   return 0;
}

int main(int argc, const char * argv[])
{
    in=1, out=1;
    int i, NumThreads;
    sem_post(&pmutex);
    sem_post(&cmutex);
    sem_init(&full,0,0);
    sem_init(&empty,0,MAXCAPACITY);

    pthread_t *producers, *consumers;
    NumThreads = abs(atoi(argv[1]));
    producers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);
    consumers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);

    for (i = 0; i < NumThreads; i++)
    {
        pthread_create(&consumers[i], NULL, &consume, NULL);
        pthread_create(&producers[i], NULL, &produce, NULL);
    }
    for (i = 0; i < NumThreads; i++)
    {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    return 0;
}

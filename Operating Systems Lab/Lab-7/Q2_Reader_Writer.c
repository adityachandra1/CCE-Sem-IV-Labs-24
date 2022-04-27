// Aditya Chandra
// 200953032

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

sem_t mutex,writeblock;
int data = 0,readcount = 0;

void *reader(void *arg) {

  int f;
  f = ((int)arg);
  sem_wait(&mutex);
  readcount = readcount + 1;
  if(readcount==1)
   sem_wait(&writeblock);
  sem_post(&mutex);
  printf("Data read by the reader%d is %d\n",f,data);
  sleep(1);
  sem_wait(&mutex);
  readcount = readcount - 1;
  if(readcount==0)
   sem_post(&writeblock);
  sem_post(&mutex);
  
}

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&writeblock);
  data++;
  printf("Data writen by the writer%d is %d\n",f,data);
  sleep(1);
  sem_post(&writeblock);
}

int main()
{
  int i,b,n;
  printf("Enter number of processes: ");
  scanf("%d",&n); 
  pthread_t rtid[5],wtid[5];

  sem_init(&mutex,0,1);
  sem_init(&writeblock,0,1);

  for(i=0;i<=n;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i);
    pthread_create(&rtid[i],NULL,reader,(void *)i);
  }

  for(i=0;i<=n;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
}

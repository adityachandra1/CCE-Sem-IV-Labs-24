#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    int i;
    char *p;
    
	sem_t sem1; // First semaphore
	sem_t sem2; // Second semaphore
    //create, initialize semaphores
    sem_init(&sem1, 1, 0);
    sem_init(&sem2, 1, 1);
    if (fork()) // Parent process
    {
        for (i = 0; i < 10; i++)
        {
             sem_wait(&sem2);// Lock the semaphore
            for (p = "ab"; *p; p++)
            {
            	
                write(1, p, 1);
		sleep(1);
                
            }
            sem_post(&sem1);
             // Release the semaphore lock
        }
        wait(NULL);
    } 
    else // Child process
    {
        for (i = 0; i < 10; i++)
        {
           //sem_wait(&sem1); // Lock the semaphore
            for (p = "cd\n"; *p; p++)
            {
                write(1, p, 1);
                sleep(1);
            }
            //sem_post(&sem2); // Release the semaphore lock
        }
    }

    // Close the Semaphores
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    return 0;
}

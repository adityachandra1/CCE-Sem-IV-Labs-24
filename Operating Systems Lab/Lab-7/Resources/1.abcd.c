#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    int i;
    char *p;
    
    if (fork()) // Parent process
    {
        for (i = 0; i < 10; i++)
        {
            for (p = "ab"; *p; p++)
            {
                write(1, p, 1);
		sleep(1);
                
            }
        }
        wait(NULL);
    }
    else // Child process
    {
        for (i = 0; i < 10; i++)
        {
            for (p = "cd\n"; *p; p++)
            {
                write(1, p, 1);
                sleep(1);
            }
        }
    }
    return 0;
}

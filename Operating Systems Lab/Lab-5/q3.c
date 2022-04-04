#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

void swap(char a[100],char b[100])
{
    char c[100];
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}

int main()
{
    char str[100][100];

    printf("Enter no of strings: ");
    int i,j,n,x;
    scanf("%d",&n);

    printf("Enter strings: ");
    
    for(int i = 0 ; i < n ; i++) {
      scanf("%s", str[i]);
    }
    
    pid_t p = fork();
    
    if(p == 0) {
       
       printf("\nFrom First child Process using Bubble Sort: ");
       
        for(i=0;i<n;i++) {
            for(j=0;j<n-i-1;j++) {
                if(strcmp(str[j],str[j+1])>0) {
                    swap(str[j],str[j+1]);
                }
            }
       }

       for(i = 0 ; i < n ; i++) {
            printf("%s ",str[i]);
        }
        printf("\n\n");
        
        exit(0);
    } else {
      
      wait(&i);
      pid_t p2 = fork();
      
      if(p2 == 0) {
         
        int pos,large;

        printf("From Second child Process by Selection sorting: ");
         
        for(i = 0 ; i < n ; i++) { 
            
            pos=i,large=0;
            for(j=i;j<n;j++) {

                if(x = strcmp(str[i],str[j]) > large) {
                    large=x;
                    pos=j;
                }
            }
            
            swap(str[i],str[pos]);
        }
              
        
       for(i = 0 ; i < n ; i++) {
            printf("%s ",str[i]);
        }
        printf("\n\n");
    
    } else {

        wait(&i);
        printf("Unsorted: ");
        for(i=0;i<n;i++) {
            printf("%s ",str[i]);
        }
        printf("\n\n");
    
        wait(&i);
    }

}

    return 0;
}
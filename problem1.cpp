//Cse 316 Problem 1

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("\n\nWelcome to the World \n");
//initiallising variables
	int n=0;
	int a=0;
	
	pid_t pid;
//creating child processes
		do
		{
			printf("Please enter a number greater than 0 to run.\n"); 
  			scanf("%d", &a);	
		}while (a <= 0);

		pid = fork();

		if (pid == 0)
		{
			printf("Child is working...\n");
			printf("%d\n",a);
			while (a!=1)
			{
				if (a%2 == 0)
				{
					a = a/2;
				}
				else if (a%2 == 1)
				{
					a = 3 * (k) + 1;
				}	
			
				printf("%d\n",a);
			}
		
			printf("Child process is done.\n");
		}
		else
		{
			printf("Parents is waiting on child process...\n");
			wait();
			printf("Parent process is done.\n");
		}
	return 0; 
}

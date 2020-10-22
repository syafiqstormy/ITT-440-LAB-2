
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
	char name[20];
        printf("Please Enter Your Name: ");
	scanf("%s", name);
	printf("Your name is %s.", name);
	printf("\n");
	exit(0);
}

void parentTask()
{
        printf("Waiting for child to finish...\n");
	wait(NULL);
	printf("Job is done. \n");
}

int main(void)
{
	for(int i=1; i<5;i++)
	{
	pid_t pid = fork();

	if(pid==0)
	{
	childTask();
	}
	
	else{
	parentTask();
		}
	}
	exit(0);
}


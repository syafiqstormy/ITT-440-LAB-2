#include <stdlib.h> // exit()
#include <unistd.h> // fork() n getpid()
#include <stdio.h> // printf()

int main (int argc, char **argv)
{
int pid; //process ID

switch (pid=fork())
{
	case 0: //fork return 0 to child
	printf("I am child process: pid=%d\n", getpid());
	break;

	default:// fork return pid to parent
	printf("I am the parent process: pid=%d, child pid=%d\n", getpid(),pid);
	break;

	case -1: //error
	perror("fork");
	exit(1);
}

exit(0);
}

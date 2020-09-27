#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int pipefd1[2];

	pipe(pipefd1);

	int pid = fork();

	if(pid==0)
	{//child
		close(pipefd1[0]);
		dup2(pipefd1[1],1);
		execl("/bin/ls","ls",NULL);
	}
	else
	{//parent
		close(pipefd1[1]);
		wait(NULL);
		dup2(pipefd1[0],0);
		execl("/bin/sort","sort",NULL);
	}

	return 0;
}

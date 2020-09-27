#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
extern char **environ;
int main()
{
	int pid = fork();
	if(pid==0)
	{// child
		execl("/bin/ls","~/Desktop",NULL);
	}
	else
	{
		wait(NULL);
		execl("/bin/pwd",NULL);
	}
	return 0;
}

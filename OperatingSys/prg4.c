#include<stdio.h>
#include<unistd.h>
extern char **environ;
int main()
{
	printf("before\n");
	char *args[] = {"~/Desktop/oslab6","-a",NULL};
	execv("/bin/ls",args);
	printf("after");
	return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

extern char **environ;
int main()
{
	int fd = open("test.txt",O_CREAT^O_WRONLY^S_IRWXU);
	printf("before\n");
	dup2(fd,1);
	printf("after\n");
	
	return 0;
}

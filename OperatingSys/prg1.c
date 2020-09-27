#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
	int fail=mkfifo("./pipe1",0666);
	if(fail)
	{
		printf("Error creating the pipe");
		return -1;
	}
	
	int fd = open("./pipe1",O_WRONLY);
	char buf[] = "vivekshah";
	int wrote = write(fd,buf,sizeof(buf));
	
	return 0;
}

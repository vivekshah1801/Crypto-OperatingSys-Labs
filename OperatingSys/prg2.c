#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
	int fd = open("./pipe1",O_RDONLY);
	char buf[100];
	int wrote = read(fd,buf,50);
	
	printf("OUTPUT FROM SECOND FILE: \n");
	write(1,buf,wrote);
	return 0;
}

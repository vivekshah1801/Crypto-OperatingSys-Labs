// parent send filename
// child send contents
// parent prints contents

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>
int main(int argc,char* argv[])
{
	int pipefd[2],pipefd2[2];
	pipe(pipefd);
	pipe(pipefd2);
	int pid = fork();
	char buf[100];
	
	if(pid==0)
	{
		close(pipefd[1]);
		close(pipefd2[0]);
		
		//child part
		bzero(buf,sizeof(buf));
		read(pipefd[0],buf,sizeof(buf));
		
		int fd = open(buf,O_RDONLY);
		int n = read(fd,buf,sizeof(buf));
		write(pipefd2[1],buf,n);
	}
	else
	{
		close(pipefd[0]);
		close(pipefd2[1]);
		
		//parent part
		write(pipefd[1],argv[1],sizeof(argv[1]));
		wait(NULL);
		bzero(buf,sizeof(buf));
		int m = read(pipefd2[0],buf,sizeof(buf));
		write(1,buf,m);
	}
	return 0;
}

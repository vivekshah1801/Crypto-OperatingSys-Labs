// child is passing the msg to parent

#include<unistd.h>
int main()
{
	int pipefd[2];
	pipe(pipefd);
	
	int pid = fork();
	char buf[100];
	
	if(pid==0)
	{
		close(pipefd[0]);
		//child part	
		int m = read(0,buf,sizeof(buf));
		write(pipefd[1],buf,m);
	}
	else
	{
		close(pipefd[1]);
		//parent part
		wait(NULL);
		int n = read(pipefd[0],buf,sizeof(buf));
		write(1,buf,n);
	}
	return 0;
}

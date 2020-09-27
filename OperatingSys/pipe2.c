#include<unistd.h>

int main()
{
	int childpid;
	
	int pipefd[2];
	int err = pipe(pipefd);
	
	if(err!=0)
	{	
	
		write(1,"error",5);
	}
	
	childpid = fork();
	
	if(childpid==0)
	{
		//child part
		char ch[1000];
		read(0,ch,1000);
		write(pipefd[1],ch,1000);
	}
	else
	{
		//parent part
		char ch2[1000];
		int n = read(pipefd[0],ch2,1000);
		write(1,ch2,1000);
	}
	
	return 0;
}

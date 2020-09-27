#include<stdio.h>
#include<unistd.h>
extern char **environ;
int main()
{
	printf("before\n");

	// \n is neccessary as it will clear the buffer.
	// otherwise the output of printf will be in buffer and then procvess image is replaced by the execl args command. So they will remain there foreever and will never show the light of the day.
	execl("/bin/ls","~/Desktop/oslab6",NULL);
	printf("after");
	return 0;
}

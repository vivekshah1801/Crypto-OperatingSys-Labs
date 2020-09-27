#include<stdio.h>
#include<pthread.h>


void * fun()
{
	printf("But the truth is: I am an ironman.\n");
	return NULL;
}

int main()
{
	pthread_t newth;
	pthread_create(&newth,NULL,fun,NULL);
	pthread_join(newth,NULL);
	printf("\t\t\t - Tonny Stark\n");
	
	return 0;
}


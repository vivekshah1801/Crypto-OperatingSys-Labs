// write a program to create two threads and each thread should call diffrent function and print diffrent message
#include<stdio.h>
#include<pthread.h>

void * fun1()
{
	printf("Yeh haath muze dede thakur.\n");
	return NULL;
}

void * fun2()
{
	printf("- Gabbar.\n");
	return NULL;
}

int main()
{
	pthread_t newth1,newth2;
	pthread_create(&newth1,NULL,fun1,NULL);
	pthread_create(&newth2,NULL,fun2,NULL);
	pthread_join(newth1,NULL);
	pthread_join(newth2,NULL);	
	
	// two cases
	// 1. create create join join
	// 2. create join create join
	
	printf("I am the last line in main.\n");
	return 0;
}


// write a program to create a single thread which should call a function passing a string to the function and function should print the string value

#include<stdio.h>
#include<pthread.h>

void * fun(void *str)
{
	printf("Passed String: %s\n",str);
	return NULL;
}

int main()
{
	pthread_t newth1;
	char *s = "I am a string passed as arg.";
	pthread_create(&newth1,NULL,fun,s);
	pthread_join(newth1,NULL);
	
	printf("I am the last line in main.\n");
	return 0;
}


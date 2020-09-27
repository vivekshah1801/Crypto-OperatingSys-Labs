// mutex locking

#include<stdio.h>
#include<pthread.h>

int count=0; //global variables are any ways initialized to zero-quivalent value.

// Initalizing Mutex Variable
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *fun(void *numsref)
{
	// locking the critical section
	pthread_mutex_lock(&m);
	count++;
	printf("Count is : %d\n",count);
	//unlocking after executing
	pthread_mutex_unlock(&m);
	return;
}

int main()
{	
	int i;	
	
	pthread_t t[4];
	
	for(i=0;i<4;i++)
	{
		pthread_create(&t[i],NULL,fun,NULL);
	}
	
	for(i=0;i<4;i++)
	{	
		pthread_join(t[i],NULL);
	}
	
	printf("I am the last line in main.\n");
	return 0;
}

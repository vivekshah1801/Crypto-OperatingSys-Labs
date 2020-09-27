// READERS WRITERS PROBLEM WITH WRITERS HAVING PRIORITY

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<time.h>
#include<unistd.h>

int readCount,writeCount;
sem_t wsem,x,y,z,rsem;
int data = 1;

void * reader(void * a)
{
	while(1)
	{
		sem_wait(&z);
			sem_wait(&rsem);
				sem_wait(&x);
					readCount++;
					if(readCount==1)sem_wait(&wsem);
				sem_post(&x);
			sem_post(&rsem);
		sem_post(&z);
		
		printf("READ  value = %d\n",data);
		
		sem_wait(&x);
			readCount--;
			if(readCount==0)sem_post(&wsem);
		sem_post(&x);
		
		sleep(1);
	}

}

void * writer(void * a)
{
	while(1)
	{
		sem_wait(&y);
			writeCount++;
			if(writeCount==1) sem_wait(&rsem);
		sem_post(&y);
		
		sem_wait(&wsem);
		data++;
		printf("WRITE value = %d\n",data);
		sem_post(&wsem);	
			
		sem_wait(&y);
			writeCount--;
			if(writeCount==0) sem_post(&rsem);
		sem_post(&y);
		
		sleep(1);
	}
}


int main()
{
	readCount = 0;
	writeCount = 0;
	sem_init(&wsem,0,1);
	sem_init(&rsem,0,1);
	sem_init(&x,0,1);
	sem_init(&y,0,1);
	sem_init(&z,0,1);
	
	pthread_t r1,r2,r3,r4,w1,w2;
	int e1 = pthread_create(&w1,NULL,writer,NULL);
	int e2 = pthread_create(&w2,NULL,writer,NULL);
	int e3 = pthread_create(&r1,NULL,reader,NULL);
	int e4 = pthread_create(&r2,NULL,reader,NULL);
	int e5 = pthread_create(&r3,NULL,reader,NULL);
	int e6 = pthread_create(&r4,NULL,reader,NULL);
	
	if((e1+e2+e3+e4+e5+e6))
		printf("Error creating threads.\n");

	e1 = pthread_join(w1,NULL);
	e2 = pthread_join(w2,NULL);	
	e3 = pthread_join(r1,NULL);
	e4 = pthread_join(r2,NULL);
	e5 = pthread_join(r3,NULL);
	e6 = pthread_join(r4,NULL);
	
	if((e1+e2+e3+e4+e5+e6))
		printf("Error joining threads.\n");
		
	return 0;
}

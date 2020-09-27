// write a program in single thread calling a function with two integer variables and they should be passed as structure pointer. Function should retrieve the value and print.

#include<stdio.h>
#include<pthread.h>

struct nums
{
	int x;
	int y;
};

void *fun(void *numsref)
{
	printf("First Num: %d\n", ((struct nums*)numsref)->x);
	printf("Second Num: %d\n", ((struct nums*)numsref)->y);
	return;
}

int main()
{		
	struct nums n;
	n.x = 10;
	n.y = 20;
	
	pthread_t newth;
	pthread_create(&newth,NULL,fun,&n);
	pthread_join(newth,NULL);
	printf("I am the last line in main.\n");
	return 0;
}

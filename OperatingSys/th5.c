// simple calc

#include<stdio.h>
#include<pthread.h>

struct nums
{
	int x;
	int y;
};

void *add(void *numsref)
{
	printf("Add: %d\n", ((struct nums*)numsref)->x + ((struct nums*)numsref)->y);
	return NULL;
}

void *sub(void *numsref)
{
	printf("Sub: %d\n", ((struct nums*)numsref)->x - ((struct nums*)numsref)->y);
	return;
}

void *mul(void *numsref)
{
	printf("Mul: %d\n", ((struct nums*)numsref)->x * ((struct nums*)numsref)->y);
	return;
}

void *div(void *numsref)
{
	printf("Div: %d\n", ((struct nums*)numsref)->x / ((struct nums*)numsref)->y);
	return;
}

int main()
{	
	int i;	
		
	struct nums n;
	n.x = 10;
	n.y = 20;
	
	pthread_t t[4];
	
	// array of function pointers
	void * f[4];
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	
	for(i=0;i<4;i++)
	{
		pthread_create(&t[i],NULL,f[i],&n);
	}
	
	for(i=0;i<4;i++)
	{	
		pthread_join(t[i],NULL);
	}
	
	printf("I am the last line in main.\n");
	return 0;
}

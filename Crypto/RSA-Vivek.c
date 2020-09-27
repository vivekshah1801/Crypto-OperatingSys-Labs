#include<stdio.h>
#include<stdlib.h>

int main()
{	
	// TODO Add Driver Code
	return 0;
}

long long fast_expo(long long x,long long y,long long m)
{
	if(y==0L)
		return 1L;
	else if(y==1L)
		return x;

	long long x2 = fast_expo(x,y/2,m);
	x2 = (x2*x2)%m;
	if(y&1L) x2 =  (x2*x)%m;
	
	return x2;
}

long long fast_expo_iter(long long x,long long y,long long m)
{
	long long res=1L;
	while(y>0)
	{
		x = (x*x)%m;
		if(y&1L)
		{
			res = (res*x)%m;
		}
		y = y>>1; // y = y/2;
	}
	return res;
}int rabin_miller_primality(long long n,int a)
{
	long long m,k;
	
	// Generating m and k
	if(n&1)
	{
		k=0;
		long long n1 = n-1;
		while(1)
		{
			if(!(n1&1))
			{
				k++;
				n1 >>= 1;
				//printf("\n%lld",n1); 
			}
			else
			{	
			
				int k1 = 1<<k;
				//printf("%d",k1);
				m = (n-1)/k1;
				//printf("*M = %d",m);
				break;
			}
		}
	}
	else
	{
		m = n-1;
		k = 0;
	}

	long long t;
	t = fast_expo(a,m,n);
	if(t==1 || t==(n-1))
		return 1;
	
	int i;
	for(i=0;i<k-1;i++)
	{
		t = (t*t)%n;
		if(t==1) return 0;
		else if(t==(n-1)) return 1;
	}
	return 0;
}

long long generate_prime()
{
	long long p=0;
	while(1)
	{
		p = rand()/10000;
		if(rabin_miller_primality(p,2)==1)
			return p;
	}
}

long long generate_prime2(long long p)
{
	long long q=0;
	while(1)
	{
		q = rand()/10000;
		if(rabin_miller_primality(q,2)==1)
			if(p!=q)
				return q;
	}
}


long long rsa()
{
	long long p = generate_prime();
	long long q = generate_prime2(p);
	printf("p = %lld, q = %lld, randmax = %lld", p,q, RAND_MAX);
	long long n = p*q;
	printf("n = %d",n);
}

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
}

int rabin_miller_primality(long long n,int a)
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
				n1 = n1>>1;
			}
			else
				m = n1>>k;
		}
	}
	else
	{
		m = n-1;
		k = 0;
	}
	
	
	long long t;
	t = fast_expo_iter(a,m,n)
	if(t==1 || t==-1)
		return 1;
	
	for(int i=0;i<k-1;i++)
	{
		t = (t*t)%m;
		if(t==1) return 0;
		else if(t==-1) return 1;
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
#define M 10000
int main()
{
	int i,j,N,count=0,prime[M],k=0;
	scanf("%d",&N);
	for(i=2;i<=N;i++)
	{
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0) break;
		}
		if(j>sqrt(i)){
			prime[k]=i;
			k++;
		}
	}
	for(i=0;i<k-1;i++)
	{
		if(prime[i+1]-prime[i]==2)count++;
	}
	printf("%d",count);
	return 0;
 } 

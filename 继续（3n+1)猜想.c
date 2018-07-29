#include<stdio.h>
#define N 101
typedef struct stru
{
	int data;
	int rest[N];
}ges;
int main()
{
	int n,i;
	ges num[N];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&num[i].data);
	for(i=0;i<n;i++)
	{
		int k=num[i].data,j=0,m=0;
		while(k!=1&&k)
		{
			if(k%2==0)
			{
				k=k/2;
				num[i].rest[j]=k;
				j++;
				for(m=0;m<n;m++)
				{
					if(num[m].data==k)
					{
						num[m].data=0;
					}
				}
			}
		else
			{
				k=(3*k+1)/2;
				num[i].rest[j]=k;
				j++;
					for(m=0;m<n;m++)
				{
					if(num[m].data==k)
					{
						num[m].data=0;
					}
				}
			}
		}
	}
	int k=0,j;
	ges temp;
	for(i=0;i<n-1;i++) 
	{
		for(j=0;j<n-i-1;j++)
		{
			if(num[j].data<num[j+1].data)
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	for(i=0;i<n&&num[i].data;i++)
	{
		printf("%d",num[i].data);
		if(num[i+1].data==0);
		else printf(" ");
	}
	return 0;
}

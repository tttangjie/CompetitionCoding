#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
int main()
{
	int n,i;
	double a,res;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf",&a);
		res+=(double)(n-i)*(i+1)*a;
	}

	printf("%.2lf\n",res);
	return 0;
}

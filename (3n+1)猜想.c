#include<stdio.h>
 main()
{
	int n=1,num=0;
	scanf("%d",&n);
	while(n!=1)
	{
		if(n%2==0)
			n=n/2;
		else
			n=(3*n+1)/2;
		num++;
	}
	printf("%d",num);
}

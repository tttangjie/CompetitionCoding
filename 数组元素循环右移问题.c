#include<stdio.h>
#define X 103
main()
{
	int N,M,i,num[X],arr[X]={0},k=0;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	i=0;
	for(k=M%N;k<N;k++)
	{
		arr[k]=num[i];
		i++;
	}
	for(k=0;k<=(M%N-1);k++)
	{
		arr[k]=num[i];
		i++;
	}
	for(i=0;i<N;i++)
	{
		printf("%d",arr[i]);
		if(i!=N-1) printf(" ");
	}
	return 0;
}

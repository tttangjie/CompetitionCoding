#include<stdio.h>

int main()
{
	int min,max,i,count=0,sum=0;
	scanf("%d%d",&min,&max);
	for(i=min;i<=max;i++){
		printf("%5d",i);
		count++;
		if(count%5==0)
			printf("\n");
		sum+=i;
	}
	if(count%5!=0)
		printf("\n");
	printf("Sum = %d",sum);
	return 0;
}

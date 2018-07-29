#include<stdio.h>
struct list{
	char name[11];
	char num[11];
	int grade;
}; 
main()
{
	struct list arr[1000];
	int x,i,max,min,m=0,n=0;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		scanf("%s",arr[i].name);
		scanf("%s",arr[i].num);
		scanf("%d",&arr[i].grade);
		getchar();
	}
	max=arr[0].grade;
	min=arr[0].grade;
	for(i=1;i<x;i++)
	{
		if(arr[i].grade>max)
		{
			max=arr[i].grade;
			m=i;
		}
		else if(arr[i].grade<min)
		{
			min=arr[i].grade;
			n=i;
		}
	}
	printf("%s %s",arr[m].name,arr[m].num);
	printf("\n");
	printf("%s %s",arr[n].name,arr[n].num);
}

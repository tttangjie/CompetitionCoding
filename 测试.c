#include<stdio.h>
#include<stdlib.h>


int main()
{
	int **a;
	int i,j;
	a=(int**)malloc(sizeof(int*)*3);
	for(i=0;i<3;i++){
		a[i]=(int*)malloc(sizeof(int)*(i+1));
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<=i;j++)
		scanf("%d",&a[i][j]);
	}
	return 0;
 } 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,i,j;
	int a[10][10] = {0};
	int m=1;
	scanf("%d",&n);
	for(i=0;i<n/2;i++){
		for(j=0;j<n-i;j++)
			if(a[i][j] == 0)
				a[i][j] = m++;

		for(j=i+1;j<n-i;j++)
			if(a[j][n-i-1] == 0)
				a[j][n-i-1] = m++;

		for(j=n-i-1;j>i;j--)
			if(a[n-i-1][j] == 0)
				a[n-i-1][j] = m++;

		for(j=n-i-1;j>i;j--)
			if(a[j][i] == 0)
				a[j][i] = m++;

	}
	if(n%2)
		a[n/2][n/2] = m;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",a[i][j]);
	printf("\n");
	}
	
	return 0;
}

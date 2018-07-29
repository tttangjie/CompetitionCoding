#include<stdio.h>

int main()
{
	int n,k,i,j;
	char c;
	scanf("%d %c",&n,&c);
	k=(n+1)/2;
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			putchar(c);
		}
		printf("\n"); 
	}
	return 0;
 } 

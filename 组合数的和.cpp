#include<stdio.h>

int main()
{
	int n, res = 0, k, num;
	scanf("%d",&n);
	num = n;
	while(num--){
		scanf("%d",&k);
		res += 11*(n-1)*k;
	}
	printf("%d\n",res);
	
	return 0;
 } 

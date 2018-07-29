#include<stdio.h>
#define N 100
//排列组合 n个位置 n-1个空 
int main()
{
	int T,n,i=0;
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("1");
		n--;
		while(n--){
			printf("0");
		} 
		printf("\n");
	}	
	return 0;
}

#include<stdio.h>

int main()
{
	int n,res=0,k=1,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		k*=i;
		res+=k;
	}
	printf("%d",res);
	
	return 0;
}

#include<stdio.h> 

int main()
{
	int n,i,res=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		res+=((1+i)*i)/2;		
	}
	printf("%d",res);
	
	return 0;
}

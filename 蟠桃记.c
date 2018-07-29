#include<stdio.h>

int main()
{
	int  n,res,i;
	while(scanf("%d",&n)!=EOF){
		res=1;
		n--; 
		while(n--){
			res=(res+1)*2;
		}
			printf("%d\n",res);
	}
	return 0;
}

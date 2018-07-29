#include<stdio.h>
//考虑相加结果会溢出
//所以选用long型结构存储数据 
int main()
{
	int T,n=1;
	long a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%ld%ld%ld",&a,&b,&c);
		if(a+b>c)
		   printf("Case #%d: true\n",n);
		else
		   printf("Case #%d: false\n",n);
		n++;
	}
	return 0;
 } 

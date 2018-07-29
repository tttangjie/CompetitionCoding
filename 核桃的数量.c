#include<stdio.h>
int main()
{
	int a,b,c,m,n,t,x;
	scanf("%d%d%d",&a,&b,&c);
	m=a;n=b;
	while(m%n!=0){
		x=m;
		m=n;
		n=x%n;
	}
	m=c;
	n=a*b/n;t=n;
	while(m%n!=0){
		x=m;
		m=n;
		n=x%n;
	}
	printf("%d",t*c/n);
	return 0;
 } 

#include<stdio.h>
#define N 52
int main()
{
	int i,flag=0;
	double k=1,n=0,count=0;
	char s[N],c,bef;
	c=getchar();
	if(c=='-') {
		k=1.5;
		c=getchar();
	}
	while(c!='\n'){
		if(c=='2')
			count++;
		n++;
		bef=c;
		c=getchar();
	}
	if((bef-'0')%2==0)
		k*=2;
	printf("%.2lf%%",(count/n)*k*100);
	return 0;
}

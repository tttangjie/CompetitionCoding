#include<stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	while(N--){
		char a,b,c,t;
		getchar();
		a=getchar();
		b=getchar();
		c=getchar();
		if(a>b){
			t=a;
			a=b;
			b=t;
		}
		if(a>c){
			t=a;
			a=c;
			c=t;
		}
		if(b>c){
			t=b;
			b=c;
			c=t;
		}
		printf("%c %c %c\n",a,b,c);
	}
	
	return 0;
 } 

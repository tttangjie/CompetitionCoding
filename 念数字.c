#include<stdio.h>
#define N 100
int main()
{
	int num[N],k=0,i,j;
	char c;
	char arr[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"}; 
	c=getchar();
	if(c=='-'){
		putchar('f');
		putchar('u');
		putchar(' ');
		c=getchar();
	}
	while(c!='\n'){
		num[k]=c-'0';
		k++;
		c=getchar();
	}
	for(i=0;i<k;i++){
		for(j=0;j<5;j++){
			if(arr[num[i]][j]!='\0')
				putchar(arr[num[i]][j]);
		}
		if(i!=k-1)
			putchar(' ');
	}
	return 0;
}

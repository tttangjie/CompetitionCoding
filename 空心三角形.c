#include<stdio.h>

int main()
{
	char c;
	int n,i,j;
	c=getchar();
	while(c!='@'){
		getchar();
		scanf("%d",&n);
		for(i=0;i<n-1;i++){
			putchar(' ');
		}
		putchar(c);
		printf("\n");
		for(j=1;j<n-1;j++){
			for(i=0;i<n-j-1;i++){
				putchar(' ');
			}
			putchar(c);
			for(i=n-j;i<n-1+j;i++){
				putchar(' ');
			}
			putchar(c);
			printf("\n");
		}
		if(n!=1){
			for(i=0;i<2*n-1;i++){
				putchar(c);
			}
			printf("\n");
		}
		getchar();
		c=getchar();
		if(c!='@'){
			printf("\n");
		}
	}
	
	return 0;
}

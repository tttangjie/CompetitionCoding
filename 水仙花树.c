#include<stdio.h>
main()
{
	int m,n,x,y,z;
	do{scanf("%d",&n);}
	while(n>1000||n<99);
		m=n;
	    z=n%10;
	    n=n/10;
	    y=n%10;
	    n=n/10;
 	    x=n;
	if(m=x*x*x+y*y*y+z*z*z)
		printf("yes\n");
		else printf("no\n");
}

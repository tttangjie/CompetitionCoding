#include<stdio.h>
#define N 20
int main()
{
	int M=3;
	while(M--)
	{
		char s[N];
	    int i=-1,n,j;
	    printf("Please input some chars until '@'\n");
     	do
		{
     		scanf("%c",&s[++i]);
		}
     	while(s[i]!='@');
    	n=i/2;
    	for(j=0;j<n;j++)
		{
    		if(s[j]!=s[i-j-1]) break;
		}
    	if(j==n) printf("Yes\n");
     	else printf("No\n");
		getchar();
	}
	return 0;
}

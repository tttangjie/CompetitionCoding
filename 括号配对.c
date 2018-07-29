#include<stdio.h>
#define M 10000
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		char s[M]={'0'},a[M]={'0'}; 
		int i,flag=1,t=0;
		gets(s);
		for(i=0;s[i];i++)
		{
			if(s[i]=='('||s[i]=='['||s[i]=='{')
			{
				a[t++]=s[i];
			}
			else if (t==0||!((s[i]==')'&&a[t-1]=='(')||(s[i]==']'&&a[t-1]=='[')||(s[i]=='}'&&a[t-1]=='{')))
			{
				flag=0;
				break;
			}
			else 
			{
				a[--t]='0';
			}
		}
		if(flag&&t==0)
		printf("Yes\n");
		else printf("No\n");
	} 
	return 1;
}

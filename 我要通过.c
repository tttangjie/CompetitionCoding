#include<stdio.h>
#include<string.h>
int isPAT(char s[])
{
	int count_p=0,count_a=0,count_t=0,mark_p=0,mark_t=0; 
	int i=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='P')
		{
			count_p++;
			mark_p=i;
		}
		if(s[i]=='T')
		{
			count_t++;
			mark_t=i;
		}
		if(s[i]=='A')
		{
			count_a++; 
		}
	}
//	printf("%d %d %d\n",mark_t-mark_p,mark_t*(mark_t-mark_p-1),strlen(s)-mark_t-1);
//	printf("%d %d\n",strlen(s),count_p+count_a+count_t);
	if(count_p+count_a+count_t==strlen(s)&&count_p==1&&count_t==1&&(mark_t-mark_p)>=2&&mark_p*(mark_t-mark_p-1)==strlen(s)-mark_t-1)
	{
		return 1;
	}
	else return 0; 
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		char s[100];
		gets(s);
		if(isPAT(s)==1)
		printf("YES") ;
		else printf("NO");
		printf("\n");
	}
	return 0;
 } 

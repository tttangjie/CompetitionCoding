#include<stdio.h>
#define N 100
int main()
{
	int n,k,i=0,j=1;
	scanf("%d",&n);
	char s[N];
	k=n/100;
	while(k){
		s[i]='B';
		i++;
		k--; 
	}
	k=(n/10)%10;
	while(k)
	{
		s[i]='S';
		i++;
		k--;
	}
	k=n%10;
	while(k)
	{
		
		s[i]=j+'0';
		j++;
		i++;
		k--; 
	}
	s[i]='\0';
	puts(s); 
	return 0;
 } 

#include <stdio.h>
#include <string.h>
#define N 100001
int main()

{
	char s[N],c[]={"1111abababa"};
	int n=2;
	int i,len;
	len=strlen(c);
	for(i=n;i<len;i++)
	{
		s[i-n]=c[i];
	}
	s[i]='\0';
	puts(s);
	
	return 0;
}

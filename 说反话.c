#include<stdio.h>
#include<string.h>
#define M 81
    
int main()
{
	char s[M],t[M][M];
	gets(s);
	int i,j,m=0,n=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==' '){
			t[m][n]='\0';
			m++;
			n=0;
			continue;
		}
		t[m][n]=s[i];
		n++;
	}
	t[m][n]='\0';
	for(i=m;i>=0;i--)
	{
		for(j=0;j<strlen(t[i]);j++)
		putchar(t[i][j]);
		if(i!=0) putchar(' ');
	}
	return 0;
 } 

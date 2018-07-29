#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n;
	char s[5];
	int a, b;
	scanf("%d", &n);
	getchar();
	while(n--) {
		scanf("%s%d%d",s, &a, &b);
		if( a<15 || a>20 || b<50 || b>70) {
			puts(s);
		}
	}
	
	
	return 0;
}

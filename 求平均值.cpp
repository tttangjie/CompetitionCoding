#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[5], b[5];
	scanf("%s%s",a,b);
	printf("%s %s\n%d %d\n%lf %lf",a,b,strlen(a),strlen(b),atof(a),atof(b));
	
	return 0;
}

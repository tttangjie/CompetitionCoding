#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int k;
	char s[10];
	int num = 0;
	scanf("%d",&k);
	getchar();
	gets(s);
	while(strcmp(s, "End") != 0) {
		if ( num == k ){
			puts(s);
			num = 0;
			gets(s);
			continue;
		}
		if(strcmp(s, "ChuiZi") == 0) {
			puts("Bu");
			num++;
			gets(s);
		} else 	if(strcmp(s, "JianDao") == 0) {
			puts("ChuiZi");
			num++;
			gets(s);
		} else	if(strcmp(s, "Bu") == 0) {
			puts("JianDao");
			num++;
			gets(s);
		}
		
	} 
	
	
	return 0;
 } 

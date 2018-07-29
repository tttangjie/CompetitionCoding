#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define N 10000
using namespace std;  

bool compare(int a, int b) {
	return a<b;
}

int main()
{
	char s[N];
	int a[N], t = 0;
	gets(s);
	for(int i = 0; i < strlen(s); i++) {
		if(s[i]>='0' && s[i]<='9'){
			a[t++] = s[i]-'0'; 
		}
	}
	sort(a, a+t, compare);
	for(int i=0; i<t; i++) {
		printf("%d",a[i]);
	}
	
	return 0;
 } 

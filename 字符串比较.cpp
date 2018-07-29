#include <stdio.h>
#include <string.h>
#include <math.h>

int compare(const char* s1, const char* s2)
{
	if(s1==NULL && s2==NULL) return 0;
	if(s1==NULL) return -1;
	if(s2==NULL) return 1;
	
	if(*s1 == 0 && *s2== 0) return 0;
	if(*s1 == 0) return -1;
	if(*s2 == 0) return 1;
	
	if(*s1<*s2) return -1;
	if(*s1>*s2) return 1;
	
	int t = compare(s1+1,s2+1);
	if(t==0) return 0;
	
//	return t/abs(t)*(abs(t)+1); //Ìî¿ÕÎ»ÖÃ
	return	t>0?t+1:t-1;
}


int main()
{
	printf("%d\n", compare("abc","abk"));
	printf("%d\n", compare("abc","a"));
	printf("%d\n", compare("abcde","abcda"));
	return 0;
}

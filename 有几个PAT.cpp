#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define N 100001
//t�ĸ���Ϊ��ǰA�������AT�ĸ���
//at�ĸ���Ϊ��ǰP�������PAT�ĸ���
//patΪ�ܵļ����� 
int main()
{
	int i,len;
	int t = 0,at = 0,pat = 0;
	char buf[N];
	gets(buf);
	len = strlen(buf);
	for (i=len-1;i>=0;i--){
		if(buf[i] == 'T')
			t++;
		if(buf[i] == 'A')
			at = (at+t)%1000000007;
		if(buf[i] == 'P')
			pat = (pat+at)%1000000007;
	}
	printf("%d\n",pat);
	return 0;
}

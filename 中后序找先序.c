#include<stdio.h>
#include<string.h>
#define N 100 

char in[N];
char post[N];
int length=0;

void find_pre(int left,int right) {
	int i,j,flag=0;
	if(left>right)
		return ;
	for(i=length-1;i>=0;i--) {
		for(j=left;j<=right;j++) {
			if(in[j]==post[i]) {
				putchar(in[j]);
				find_pre(left,j-1);
				find_pre(j+1,right);
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
}

int main()
{
	gets(in);
	gets(post);
	length=strlen(in);
	find_pre(0,length-1);
	printf("\n");
	return 0;
}

#include<stdio.h>
#define N 10000
typedef struct{
	char c;
	int f;
}str;
int main()
{
	str arr[N];
	char brr[N];
	int m=0,n=0,i,j;
	char ch=getchar();
	while(ch!='\n'){
		arr[m].c=ch;
		m++;
		ch=getchar();
	}
	ch=getchar();
	while(ch!='\n'){
		brr[n]=ch;
		n++;
		ch=getchar();
	}
	for(i=0;i<m;i++){
		arr[i].f=0;
	} 
	for(j=0;j<n;j++){
		for(i=0;i<m;i++){
			if(arr[i].c==brr[j])
				arr[i].f=1;
		}
	}
	for(i=0;i<m;i++){
		if(arr[i].f==0)
			putchar(arr[i].c);
	}
	return 0;
 } 

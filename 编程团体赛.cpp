#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1001

int main()
{
	int team,mem,res;
	int a[N] = {0};
	int n,i,max = 0;
	scanf("%d",&n);
	while(n--){
		scanf("%d-%d%d",&team,&mem,&res);
		a[team]+=res;
	}
	for(i=1;i<N;i++){
		if(a[i]>a[max])
			max = i;
	}
	printf("%d %d",max,a[max]);
	return 0;
}

#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define N 100000

int main()
{
	int a[N],flag[N];
	int n,i = 0,count;
	int maxnum = -1,minnum = 1000000000;
	memset(flag,1,sizeof(flag));
	for(i=0;i<N;i++)
		flag[i] = 1;
	scanf("%d",&n);
	count = n;
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i] >= maxnum){
			maxnum = a[i];
		}
		else{
			flag[i] = 0;
			count--;
		}
	}
	for(i=n-1;i>=0;i--){
		if(a[i] <= minnum){
			minnum = a[i];
		}
		else if(a[i]>minnum && flag[i]==1){
			flag[i] = 0;
			count--;
		}
	}
	printf("%d\n",count);
	for(i=0;i<n;i++){
		if(flag[i]){
			printf("%d",a[i]);
			count--;
			if(count!=0)
				printf(" ");
		}
	}
	printf("\n");
	return 0; 
}

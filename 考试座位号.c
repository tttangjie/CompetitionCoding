#include<stdio.h>
#define N 1001
typedef struct {
	char num[14];
	int a;
	int b;
}info;

int main()
{
	info arr[N];
	int brr[N],j;
	int n,i,k=0,m;
	scanf("%d",&n);
	while(k<n){
	getchar();
		for(i=0;i<14;i++){
			arr[k].num[i]=getchar();
		}
		getchar();
		scanf("%d%d",&arr[k].a,&arr[k].b);
		k++;
	}
	scanf("%d",&m);
	k=0;
	while(k<m){
		scanf("%d",&brr[k]);
		k++;
	}
	for(k=0;k<m;k++){
		for(i=0;i<n;i++){
			if(brr[k]==arr[i].a){
				for(j=0;j<14;j++){
					putchar(arr[i].num[j]);
				}
				printf(" %d",arr[i].b);
				if(k<m-1)
					printf("\n");
				break;
			}
		}
	}
	return 0;
}

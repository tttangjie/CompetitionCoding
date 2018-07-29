#include<stdio.h>
#define M 100
int main()
{
	int i,N,j=1,k;
	int arr[M]={0,1};
	char c;
	scanf("%d",&N);
	getchar();
	c=getchar();
	for(i=2;arr[i]<=1000;i++){
		arr[i]=arr[i-1]+2*(2*i-1);
	}
	while(arr[j]<=N){
		j++;
	}
	for(i=j-1;i>=1;i--){
		k=j-1-i;
		while(k--){
			putchar(' ');
		}
		k=2*i-1;
		while(k--){
			putchar(c);
		}
		printf("\n");
	}
	for(i=2;i<j;i++){
		k=j-1-i;
		while(k--){
			putchar(' ');
		}
		k=2*i-1;
		while(k--){
			putchar(c);
		}
		printf("\n");
	}
	printf("%d",N-arr[j-1]);
	return 0;
  
 } 

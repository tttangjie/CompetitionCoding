#include<stdio.h>
#define N 100
//������� n��λ�� n-1���� 
int main()
{
	int T,n,i=0;
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("1");
		n--;
		while(n--){
			printf("0");
		} 
		printf("\n");
	}	
	return 0;
}

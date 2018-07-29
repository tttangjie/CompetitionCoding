#include<stdio.h>
#include<string.h>
#define M 4
#define N 255
#define X 100000000
int main(){
	int n,i,j,key,t,sum;
	int arr[M][N];
	while(scanf("%d",&n)!=EOF){
		memset(arr,0,sizeof(arr));
		arr[0][0] = 1;
		arr[1][0] = 1;
		arr[2][0] = 1;
		arr[3][0] = 1;
		for(i = 4;i < n ;i++){
			j = 0;
			key = 0;
			while(arr[0][j]||arr[1][j]||arr[2][j]||arr[3][j]){
				sum = arr[0][j]+arr[1][j]+arr[2][j]+arr[3][j]+key;
				arr[i%4][j] = sum % X;
				key = sum / X;
				j++;
			}
			arr[i%4][j++] = key;
		}
		if(key == 0) 
			j--;
		printf("%d",arr[(i-1)%4][j-1]);
		if(j-2 >= 0)
			for(t = j-2 ;t >= 0;t--){
				printf("%08d",arr[(i-1)%4][t]);
			}
		printf("\n");
	}
	return 0;
} 

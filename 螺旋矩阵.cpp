#include<stdio.h>
#include<string.h>
#include<algorithm> 
#include<math.h>
#define N 10000
using namespace std;

int cmp(const void *a,const void *b){
	return *(int *)b - *(int *)a;
}

int main()
{
	int n, i, j, k = 0;
	int col, line;
	int a[N] = {0}, min = N-1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort((void *)a,n,sizeof(int),cmp);
	for(i=1;i<=sqrt(n);i++){
		if(n%i == 0){
			if(n/i-i<min){
				min = n/i;	
				col = i;
			}
		}
	}
	line = n/col;
	i = 0;
	j = 0;
	int res[line][col];
	memset(res,0,sizeof(res));
	while(k<n){
		while(j<col && res[i][j] == 0){
			res[i][j] = a[k];
			j++;k++;
		}
		i++;j--;
		while(i<line && res[i][j] == 0){
			res[i][j] = a[k];
			i++;k++;
		}
		i--;j--;
		while(j>=0 && res[i][j] == 0){
			res[i][j] = a[k];
			j--;k++;
		}
		i--;j++;
		while(i>=0 && res[i][j] == 0){
			res[i][j] = a[k];
			i--;k++;
		}
		i++;j++;
	}	
	for(i=0;i<line;i++){
		for(j=0;j<col;j++){
			printf("%d",res[i][j]);
			if(j!=col-1)
				printf(" ");
		}
		printf("\n");
	}

		
	return 0;
 } 

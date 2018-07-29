#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int main()
{
	int ra, ca, rb, cb;
	int a[N][N], b[N][N];
	scanf("%d%d", &ra, &ca);
	int res;
	for (int i = 0; i<ra; i++) {
		for(int j = 0; j<ca; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d%d", &rb, &cb);
	for (int i = 0; i<rb; i++) {
		for(int j = 0; j<cb; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	if(ca != rb) {
		printf("Error: %d != %d\n", ca, rb);
		return 0;
	}
	printf("%d %d\n", ra, cb);
	for (int i = 0; i<ra; i++) {
		for(int j = 0; j<cb; j++) {
			res = 0;
			for(int t = 0; t<ca; t++){
				res += a[i][t]*b[t][j];
			}
			printf("%d", res);
			if(j!=cb-1)
				printf(" ");
		}
		if(i != ra-1)
			printf("\n");
	}
	
	return 0;
}

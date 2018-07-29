#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	int n, flag = 0;
	int i, j, k;
	double t;
	scanf("%d", &n);
	for(int i = 0; i<=sqrt(n);i++) {
		for(int j = i; j<=sqrt(n);j++) {
			for(int k = j; k<=sqrt(n); k++) {
				t = sqrt(n-i*i-j*j-k*k);
					if(t ==(int)t){
						printf("%d %d %d %d\n", i, j, k, (int)t);
						flag = 1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
	
	return 0;
}

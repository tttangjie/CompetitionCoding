#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


int flag[10];
int a[6];

int find() {
	for(int i = 0; i<6; i++) {
		int k = 0;
		while(a[i]) {
			flag[ a[i]%10 ]++;
			if(flag[ a[i]%10 ] >2) return 0;
			a[i] /=10;
			k++;
		}
		if(k<3) return 0;
	}
	return 1;
}

int main() {
	for(int i=100; i<=999; i++) {
		for(int j=100; j<=999; j++) {
			memset(flag, 0 , sizeof(flag));
			memset(a, 0, sizeof(a));
			a[0] = i;
			a[1] = j;
			a[2] = i*(j%10);
			a[3] = i*(j/10%10);
			a[4] = i*(j/100);
			a[5] = i*j;
			if(find()) {
				printf("%d\n",i*j);
			}
		}
	}
	
	
	return 0;
} 

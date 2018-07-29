#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[6];

void find(int k) {
	if(k==6) {
		printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4], a[5]);
		return;
	}
	
	for(int i = a[k-1]+1; i<=7; i++) {
		a[k] = i;
		find(k+1);
	}
}

int main() {
	memset(a, 0, sizeof(a)); 
	find (1);
	return 0;
}

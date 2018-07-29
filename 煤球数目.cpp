#include<stdio.h>

int main(){
	int res = 0;
	for(int i = 1; i<=100; i++) {
		res+=(i+1)*i/2;
	}
	printf("%d",res);
	
	return 0;
} 

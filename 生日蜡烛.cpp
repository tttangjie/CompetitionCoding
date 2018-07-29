#include<stdio.h>

int main() {
	
	for(int i = 0; i<=100; i++) {
		for(int j=i+1; j<=100;j++) {
			if((i+j)*(j-i+1)/2 == 236){
				printf("%d %d",i, j);
				break;
			}
				
		}
	}
	
	return 0;
}

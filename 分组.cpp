#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int group[8][5] = {0};
	int work[8]={1,1,2,2,2,3,3,3};
	int i,j;
	srand(time(NULL));
	for(i = 1; i <= 40; i++) {
		{
			j = rand() % 40;	
		}
	
		while(*(group[0] + j % 40) != 0)
			j++;
		*(group[0] + j % 40) = i;
	}
	for(i=0; i<8; i++) {
		printf("µÚ%d×é£º",i+1);
		for(j=0; j<5; j++)
			printf("%d\t",group[i][j]);
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int group[8][1] = {0};
	int i,j;
	srand(time(NULL));
	for(i = 1; i <= 8; i++) {
		j = rand() % 8;
		while(*(group[0] + j % 8) != 0)
			j++;
		*(group[0] + j % 8) = i;
	}
	for(i=0; i<8; i++) {
		printf("��%d�飺",i+1);
		for(j=0; j<1; j++)
			printf("%d��\t",(group[i][j]+3)/3);
		printf("\n");
	}
	return 0;
}

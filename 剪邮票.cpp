#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[6];
int map[5][6];
int flagx[] = {0, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
int flagy[] = {0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
int count = 0; 
int y[] = {-1, 1, 0, 0};
int x[] = {0, 0, -1, 1};
int num;

void check(int k) {
	for(int i=0; i<4; i++) {
		int ny = flagy[ a[k] ] + y[i];
		int nx = flagx[ a[k] ] + x[i];
		if(map[ny][nx] == 1) {
			map[ny][nx] = 0;
			num ++;
			for(int j = 1; j<6; j++)
				if(a[j] == (ny-1)*4+nx)
					check(j);
		}
	}
}


void find(int k) {
	if(k == 6) {
		memset(map, 0, sizeof(map));
					
		for(int i = 1; i<6; i++) 
			map[flagy[a[i]]][flagx[a[i]]] = 1;
		num = 1;
		map[flagy[a[1]]][flagx[a[1]]] = 0;
		check(1);
		if(num == 5)
			count++;
		return;
	}
	
	for(int i = a[k-1]+1; i<=12; i++) {
		a[k] = i;
		find(k+1);
	}
}

int main() {
	for(int i=0; i<5; i++) {
		for(int j=0; j<6; j++)
			map[i][j] = 0;
	}
	find(1);
	printf("%d\n", count);
	return 0;
}

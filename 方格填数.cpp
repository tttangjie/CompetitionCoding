#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag[10] = {0};
int map[5][6];
int count = 0;
int num;
int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

int check(int n, int a, int b) {
	for(int i = 0; i<8; i++) {
		if(map[a+x[i]][b+y[i]] == n+1 || map[a+x[i]][b+y[i]] == n-1)
			return 0;
	}
	return 1;
}

void dfs(int k, int a, int b) {
	if(k == 11) {
		count++;
		return ;
	}
	
	for(int n=0; n<=9; n++) {
		if(flag [n] == 1)
			continue;
		if(check(n, a, b) == 0)
			continue;
			
		flag[n] = 1;
		map[a][b] = n;
		if(b < 4)
			dfs(k+1, a, b+1);
		else
			dfs(k+1, a+1, 1);
		flag[n] = 0;
		map[a][b] = -100;
		
	}
}

int main() {
	
	for(int i=0; i<5; i++) {
		for(int j=0; j<6; j++) {
			map[i][j] = -100;
		}
	}
	dfs(1, 1, 2);
	printf("%d",count);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
int map[5][6] = {0};
int visited[5][6] = {0};
//int check[10]= {0};
int x[13] = {0,1,1,1,1,2,2,2,2,3,3,3,3} ;
int y[13] = {0,1,2,3,4,1,2,3,4,1,2,3,4} ;
int px[5] = {0,-1,1,0,0};
int py[5] = {0,0,0,-1,1};
int count=0;
int ans = 0;

void check(int p,int q) {
	int i;
	for(i=1; i<=4; i++) {
		if(!visited[p+px[i]][q+py[i]] && map[p+px[i]][q+py[i]] == 1) {
			visited[ p+px[i] ][ q+py[i] ] = 1;
			check( p+px[i] , q+py[i] );
			++count;
		}
	}
}


void dfs(int k,int last) {
	int i;
	if(k==6) {

//		printf("\n");
//		Sleep(500);

		count=0;
		memset(visited,0,sizeof(visited));
		for(i=1; i<=12; i++) {
			if(map[ x[i] ][ y[i] ]==1) {
				++count;
				visited[ x[i] ][ y[i] ] = 1;
				check(x[i],y[i]);
				break;
			}
		}
		if(count == 5)
			++ans;
		return ;
	}

	for(i=last+1; i<=12; i++) {
		map[x[i]][y[i]]=1;



//printf("%d ",i);



		dfs(k+1,i);
		map[x[i]][y[i]]=0;
	}



}

int main() {
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}

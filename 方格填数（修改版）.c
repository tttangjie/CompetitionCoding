#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int flag[10]={0};
int map[5][6]={0};
int y[13]={0,1,1,1,1,2,2,2,2,3,3,3,3};
int x[13]={0,1,2,3,4,1,2,3,4,1,2,3,4};
int py[9]={0,1,1,1,0,-1,-1,-1,0};
int px[9]={0,-1,0,1,1,1,0,-1,-1};
int count=0;
int res=0;

void check(p,q){
	int i;
	for(i=1;i<=8;i++){
		if(abs(map[p][q]-map[p+py[i]][q+px[i]])==1){
			count++;
			break;
		}
			
	}
}


void dfs(int k){
	int i;
	if(k==12){
		count=0;
		for(i=2;i<=11;i++){
			check(y[i],x[i]);
		} 
		if(count==0)
			res++;
	}
	for(i=0;i<=9;i++)
	{
		if(flag[i]==1) continue;
		flag[i]=1;
		map[y[k]][x[k]]=i;
		dfs(k+1);
		flag[i]=0;
	}
}

int main()
{
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<6;j++) {
			if(i==0||i==4||j==0||j==5)
				map[i][j]=100;
		}
	}
	map[1][1]=100;
	map[3][4]=100; 
	dfs(2);
	printf("%d",res);
	return 0;
}

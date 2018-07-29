#include<stdio.h>
int a[14]={0};
int res=0;
void dfs(int k,int last)
{
	int i;
	if(k==14){
		res++;
		return ;
	}
	for(i=last;i<=13;i++){
		if(a[i]==4)
			continue;
		a[i]++;
		dfs(k+1,i);
		a[i]--;
	}
}

int main()
{
	dfs(1,1);	
	printf("%d",res);
	return 0;
}

#include<stdio.h>
int fb[41]={0,1,2};
//��������洢���ݣ����õݹ������ظ������������г�ʱ 

int main()
{
//	freopen("stair.in","r",stdin);
//	freopen("stair.out","w",stdout);
	int T,n,i;
	for(i=3;i<41;i++){
		fb[i]=fb[i-1]+fb[i-2];
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",fb[n]);
	}
	return 0;
 } 

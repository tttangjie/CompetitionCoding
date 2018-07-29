#include<stdio.h>
#define N 100000
int max(a,b){
	if(a>=b) return a;
	return b;
}
typedef struct{
	int val;
	int start;
	int end;
}maxsum;
int main()
{
	int n,m=1,k,i;
	int arr[N],res;
	maxsum maxs[N];
	scanf("%d",&n);
	while(m<=n){
		res=0;
		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d",&arr[i]);
		}
		maxs[0].val=arr[0];
		maxs[0].start=0;
		maxs[0].end=0;
		for(i=1;i<k;i++){
			if(maxs[i-1].val+arr[i]>arr[i]){
				maxs[i].start=maxs[i-1].start;
				maxs[i].end=i;
				maxs[i].val=maxs[i-1].val+arr[i];
			}
			else{
				maxs[i].start=i;
				maxs[i].end=i;
				maxs[i].val=arr[i];
			}
		}
		for(i=1;i<k;i++){
			if(maxs[res].val<maxs[i].val){
				res=i;
			}
		}
		printf("Case %d:\n",m);
		printf("%d %d %d\n",maxs[res].val,maxs[res].start+1,maxs[res].end+1);
		if(m!=n)
			printf("\n");
		m++;
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
	int t,n,num,sum,a,flag[101]={0};
	scanf("%d",&t);
	while(t--){
		memset(flag,0,sizeof(int)*101);
		scanf("%d",&num);
		n=num-1;
		sum=0;
		while(n--){
			scanf("%d",&a);
			flag[a]++;
			sum+=a;
		}
		printf("%d %.2lf\n",2*sum/(3*num-2),1.0/(flag[2*sum/(3*num-2)]+1));
	}

	return 0;
 } 

#include<stdio.h>
#include<math.h>
int a[10];
int check[10]={0};
int count=0;
double y,z;
void dfs(int k){
	int i;
	if(k==10){
		y=(double)a[2]/(double)a[3];
		z=(double)(a[4]*100+a[5]*10+a[6])/(double)(a[7]*100+a[8]*10+a[9]);
		if(fabs(a[1]+y+z-10)<1e-6)
		{
			count++;
			printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4]*100+a[5]*10+a[6],a[7]*100+a[8]*10+a[9]);
		}
	return ;
	}
	
	for(i=1;i<=9;i++){
		if(check[i]==1)
			continue;
		a[k]=i;
		check[i]=1;
		dfs(k+1);
		check[i]=0;	
	}
	
}

int main()
{
	dfs(1);
	printf("%d",count); 
	return 0;
}

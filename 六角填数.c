#include<stdio.h>
int a[10];
int check[13]={0};

void dfs(int k)
{
	int i,b,c,d,e,f,g;
	if(k==10){
		g=1+a[1]+a[4]+a[6];
		b=1+a[2]+a[5]+a[9];
		c=8+a[1]+a[2]+a[3];
		d=8+a[4]+a[7]+3;
		e=3+a[3]+a[5]+a[8];
		f=a[6]+a[7]+a[8]+a[9];
		if(g==b&&g==c&&g==d&&g==e&&g==f)
			printf("%d",a[4]);
		
	}
	
	for(i=2;i<=12;i++){
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
	check[3]=1;
	check[8]=1;	

	dfs(1);
	return 0;
}

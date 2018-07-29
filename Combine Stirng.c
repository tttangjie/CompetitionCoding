#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#define N 1001
int main()
{
	char a[N],b[N],c[N];
	int dp[N][N];
	int lena,lenb,lenc,i,j;
	while(~scanf("%s%s%s",a+1,b+1,c+1)!=EOF){
		memset(dp,0,sizeof(dp));
		lena=strlen(a+1);
		lenb=strlen(b+1);
		lenc=strlen(c+1);
		if(lena+lenb!=lenc) {
			printf("No\n");
			continue;}
		dp[0][0]=1;
		for(i=0;i<=lena;i++)
		{
			for(j=0;j<=lenb;j++)
			{
				if(i==0&j==0) continue;
				if(i>0&&c[i+j]==a[i])
					dp[i][j]=dp[i-1][j];
				if(j>0&&c[i+j]==b[j])
					dp[i][j]=dp[i][j-1];
			}
		}
		if(dp[lena][lenb]==1) puts("Yes");
		else puts("No");
	}	
	return 0;
}

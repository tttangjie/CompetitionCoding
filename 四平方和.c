#include<stdio.h>
#include<math.h>
#define N 2300
int main()
{
	int i,j,k,count=0,n,t=3,temp,flag=0;
	int a[N],res[4]={0};
	double x;
	scanf("%d",&n);
	/*a[0]=0;
	for(i=1;a[i-1]<=5000000;i++){
		a[i]=i*i;
		count++;
	}
	for(i=count-1;i>=0;i--){
		if(n==0) break;
		if(n>=a[i]){
			n-=a[i];
			res[t]=i;
			t--;
			i++;
		}
	}
*/
	for(i=0;i*i<=n;i++)
	{
		for(j=0;j*j<=n;j++)
		{
			for(k=0;k*k<=n;k++)
			{
				temp=n-i*i-j*j-k*k;
				x=sqrt((double)temp);
				if(fabs(x-(int)x)<1e-6){	
					printf("%d %d %d %d",i,j,k,(int)x);
					flag=1;
					break;
				}
			}
			if(flag==1) break;
		}
		if(flag==1) break;
	}
//	printf("%d %d %d %d",res[0],res[1],res[2],res[3]);
	return 0;
}


# include<stdio.h> 

int a[9]={0} ; //Èý1 Ñò2 Éú3 Èð4 Æø5 Ïé6 »Ô7 Ï×8
int flag[10]={0};

void dfs(int k){
	int i;
	int x,y,z;
	if(k==9){
		if(a[1]==0||a[6]==0)	return ;
		x=a[6]*1000+a[4]*100+a[3]*10+a[7];
		y=a[1]*1000+a[2]*100+a[8]*10+a[4];
		z=a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
		if(x+y==z){
			printf("%d %d %d",x,y,z);
		}
	}
	
	for(i=0;i<=9;i++)
	{
		if (flag[i]==1)
			continue;
		a[k]=i;
		flag[i]=1;
		dfs(k+1);
		flag[i]=0;
	}
	
}

int main()
{
	dfs(1);
	
	
	return 0;
 } 


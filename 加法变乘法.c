#include<stdio.h>

int flag[49]= {0}; //从1记录的48个符号
int a[2]= {0};
int res=1;
void dfs(int k,int last) {
	int i,t=0;
	res=1;
	if(k==3) {
		for(i=1; i<=48; i++) {
			if(flag[i]==0)
				res+=i+1;
			if(flag[i]==1)
				res=res-i+(i+1)*i;
		}
//		printf("%d\n",res);
		if(res==2015) {
			for(i=1; i<=48; i++) {
				if(flag[i]==1) {
					a[t]=i;
					t++;
				}
				if(a[1]-a[0]!=1)
					printf("%d\n",a[0]);
			}	
		}
		return ;
	}
	for(i=1+last; i<=48; i++) {
		flag[i]=1;
		dfs(k+1,i);
		flag[i]=0;
	}

}

int main() {
	dfs(1,0);

	return 0;
}

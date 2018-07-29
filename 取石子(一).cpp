#include<stdio.h>
//a先取走n%（m+1）个 
//b无论取（1~m）个中哪一个数
//a总能补齐m+1个 最后可以一次取走所有物品 
int main()
{
	int num,n,m; //n为石子总数，m为最多取的个数 
	scanf("%d",&num);
	while(num--){
		scanf("%d%d",&n,&m);
		if(n%(m+1) == 0) 
			puts("Lose");
		else
			puts("Win");
	}
} 

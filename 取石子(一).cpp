#include<stdio.h>
//a��ȡ��n%��m+1���� 
//b����ȡ��1~m��������һ����
//a���ܲ���m+1�� ������һ��ȡ��������Ʒ 
int main()
{
	int num,n,m; //nΪʯ��������mΪ���ȡ�ĸ��� 
	scanf("%d",&num);
	while(num--){
		scanf("%d%d",&n,&m);
		if(n%(m+1) == 0) 
			puts("Lose");
		else
			puts("Win");
	}
} 

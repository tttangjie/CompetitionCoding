#include<stdio.h>
//������ӽ�������
//����ѡ��long�ͽṹ�洢���� 
int main()
{
	int T,n=1;
	long a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%ld%ld%ld",&a,&b,&c);
		if(a+b>c)
		   printf("Case #%d: true\n",n);
		else
		   printf("Case #%d: false\n",n);
		n++;
	}
	return 0;
 } 

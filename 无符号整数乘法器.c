#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define num 4
int mul(bool int1[],bool int2[]){
	int i,j,a[num+num]={0},k=0,m=0,value=0;
	for(i=num-1;i>=0;i--) //��λ��˵Ľ����λ��� 
	    for(j=num-1;j>=0;j--)
	       a[i+j+1]+=int1[i]*int2[j];
	for(i=num+num-1;i>=0;i--){//����ӽ�����Ϻ���λ�Ľ�λȡ��Ϊ��ֵ��kΪ��λ 
		m=a[i]+k;
		a[i]=m%2;
		k=m/2;
	}
	for(i=0;i<num;i++)//������λ����int1[]��
		int1[i]=a[i];
	for(i=num;i<num+num;i++){//������λ����int2[]�� ������ֵ 
	    int2[i-num]=a[i];
	    if(a[i]==1)
		    value+=pow(2,2*num-i-1);
	}
	
	for(i=0;i<num+num;i++)//�����˵Ľ�� 
	    printf("%d",a[i]);
	printf("\n"); 
	return value;
}

int main()
{
	bool int1[num],int2[num];
	int i,ZF=0,value=0;
	for(i=0;i<num;i++)
		int1[i]=getchar()-'0';
	getchar();
	for(i=0;i<num;i++)
		int2[i]=getchar()-'0';
	getchar();
	value=mul(int1,int2);
	for(i=0;i<num;i++)
	    ZF+=int1[i];
	if(ZF==0)
	  printf("������Ϊ��%d\tû�����\n",value);
	else
	  printf("������Ϊ��%d\t���\n",value); 
	return 0;
 } 

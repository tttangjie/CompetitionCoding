#include<stdio.h> 
#include<stdbool.h>
#include<math.h>
unsigned int unsignedToValue(bool binary[]) 
{
	unsigned int x=0;
	int i;
	for(i=31;i>=0;i--)
	{
		if(binary[i]==1) 
	    	x+=pow(2,i);
	}
	return x;
}

int intToValue(bool binary[])
{
	bool bitv[32];
	int y=0,i,flag=0,t;//falgΪ���λ��־ 
	for(i=0;i<32;i++) //copy���� 
	   bitv[i]=binary[i];
	if(bitv[31]==0){
		for(i=30;i>=0;i--)
			if(bitv[i]==1)
			    y+=pow(2,i);
		return y;
	}
	else
	{
		for(i=0;i<32;i++)//�����Ƽ�һ��ȡ�� ����  
		{
			t=bitv[i]+1+flag;//��ֵ�ӽ�λ�ĺ� 
			bitv[i]=(t+1)%2;//ȡ��Ϊ��ֵ�� +1����ȡ������ 
			flag=t/2;
		}
		for(i=30;i>=0;i--)
		    if(bitv[i]==1) 
	    	    y+=pow(2,i);
		return -y;
	}
}

//�ǹ����0������ȫΪ0��β������ return 0��
//����󣬽���ȫΪ1��β������ȫΪ0 return 1.#INF00
//NaN ����ȫΪ1��β�����ֲ�ȫΪ0   return 1.#QNAN0
float floatToValue(bool binary[])
{
	int sign=binary[31]==0?1:-1;//����λ 
	int i,k=0,num1=0,num2=0;//num1��¼������1��������num2��¼β����1������ 
	float value=1; 
	for(i=30;i>=23;i--)//�������ֵ 
	{
		if(binary[i]==1) 
		{
			num1++;
	    	k+=pow(2,i-23);
	    }
	}
	k-=127;//����-27Ϊָ�� 
	for(i=22;i>=0;i--)//β�����ֵļ��� 
	{
		if(binary[i]==1){
		  num2++;
		  value+=pow(2,-1*(23-i));
     	}
	}
	if(num1==0&&num2==0)
	    printf("\n�˸�����Ϊ 0"); 
	else if(num1==8&&num2==0)
	    printf("\n�˸�����Ϊ �����");
	else if(num1==8&&num2!=0)
	    printf("\n�˸�����Ϊ ����"); 
	else printf("\nת��Ϊ��������%.60f",sign*value*pow(2,k));
	return sign*value*pow(2,k);
}

int main()
{
	bool t[32]={0},binary[32]={0};
	int i=0,n=0;
	char c;
	float f;
	while((c=getchar())!='\n')
	{
		t[i++]=c-'0';
	}
	while(--i!=-1)
	{
		binary[n++]=t[i];
	}
	for(i=31;i>=0;i--)
	{
		printf("%d",binary[i]);
	}
	printf("\nת��Ϊ�޷�������%u",unsignedToValue(binary));
	printf("\nת��Ϊ�з�������%d",intToValue(binary));
    floatToValue(binary);
	return 0;
}

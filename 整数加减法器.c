#include<stdio.h> 
#include<stdbool.h> 
#include<math.h>
#define num 4 //numλ�ļӼ������� 
bool OF=0,CF=0,SF=0,ZF=0; 

int addsub(bool int1[],bool int2[],bool flag){
	bool val[num+1]={0};
	int k=0,m=num,value=0,i,t,k0=0;
	if(flag==1){  //����ʱ������ߵĲ��� 
		for(i=num-1;i>=0;i--){
			t=int2[i]+1+k;
			int2[i]=(t+1)%2;
			k=t/2;
		}
	} 

	k=0;//�ӷ���λ��־��ʼ��Ϊ0 
	for(i=num-1;i>=0;i--,m--){//�ӷ����� 
	   	val[m]=(int1[i]+int2[i]+k)%2;
	   	k=(int1[i]+int2[i]+k)/2;
	   	if(i==1) k0=k;
	}
	val[m]=k;//���ʱ�����λ 
	
	for(i=num;i>=1;i--){//�����޷�����ֵ 
		if(val[i]==1) 
	    	value+=pow(2,num-i);
	}
	
	//���ZF,OF,SF,CF
	if(value==0) ZF=1; 
	OF=val[0]^k0;// Cn���Cn-1,k0Ϊ��λ��λ 
	SF=val[1];// ����λΪ���������λ 
	CF=flag^val[0];// Cout���Cin
	return value;//����Ϊ�޷��Ž�� 
}

int main()
{
	bool int1[num],int2[num],flag,v[num]={0};
	int i,n=0,value_n,value_y=0,t,k=0;
	for(i=0;i<num;i++)
		int1[i]=getchar()-'0';
	getchar();
	for(i=0;i<num;i++)
		int2[i]=getchar()-'0';
	getchar();
	printf("Please choose sub(1) or add(0):");//flagΪ1 ��ʾ������flagΪ0 ��ʾ�ӷ� 
	flag=getchar()-'0';
	getchar();
	value_n=addsub(int1,int2,flag);
	printf("\nOF=%d,CF=%d,SF=%d,ZF=%d",OF,CF,SF,ZF);
	
	t=value_n;//
	for(i=0;i<num;i++){//���޷�����ֵת��Ϊ�����ƴ洢��bool�������� 
		if(t-pow(2,num-i-1)>=0) {
			v[i]=1;
			t-=pow(2,num-i-1);
		}
	}
	
	printf("\n������Ϊ��");
	for(i=0;i<num;i++)
		printf("%d",v[i]);
	
	if(v[0]==0) value_y=value_n;
	else{
		for(i=num-1;i>=0;i--){//�����Ƽ�һ��ȡ�� ����  
			t=v[i]+1+k;//��ֵ�ӽ�λ�ĺ� 
			v[i]=(t+1)%2;//ȡ��Ϊ��ֵ�� +1����ȡ������ 
			k=t/2;
		}
		for(i=1;i<num;i++)
		    if(v[i]==1) 
	    	    value_y+=pow(2,num-i-1);
	    value_y*=-1;
	}
		
	//�޷��ż����������CF=1 
	if(CF==1) printf("\n\nsum=%d\t�޷�������£��������",value_n);
	   else printf("\n\nsum=%d\t�޷�������£�δ�������",value_n);
	//�����ż����������OF=1 
	if(OF==1) printf("\nsum=%d\t�з�������£��������",value_y);
	else printf("\nsum=%d\t�з�������£�δ�������",value_y);
	return 0;
}

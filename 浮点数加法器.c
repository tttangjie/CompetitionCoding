#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define n 32

float floatToValue(bool binary[])
{
	int sign=binary[0]==0?1:-1;//����λ 
	int i,k=0,num1=0,num2=0;//num1��¼������1��������num2��¼β����1������ 
	float value=1; 
	for(i=1;i<=8;i++)//�������ֵ 
	{
		if(binary[i]==1) 
		{
			num1++;
	    	k+=pow(2,8-i);
	    }
	}
	k-=127;//����-27Ϊָ�� 
	for(i=31;i>8;i--)//β�����ֵļ��� 
	{
		if(binary[i]==1){
		  num2++;
		  value+=pow(2,-1*(i-8));
     	}
	}
	if(num1==0&&num2==0)
	    printf("\n�˸�����Ϊ 0"); 
	else if(num1==8&&num2==0)
		printf("\n�˸�����Ϊ �����");
	else if(num1==8&&num2!=0)
		printf("\n�˸�����Ϊ ����"); 
	else printf("\nת��Ϊ��������%.20f",sign*value*pow(2,k));
	return sign*value*pow(2,k);
}


int subComplement(bool a[],bool b[]) {//������� 
    int i,k=0,t,m,move=0;
	for(i=8;i>=1;i--){//���㱻����b�Ľ���Ĳ��� 
			t=b[i]+1+k;
			b[i]=(t+1)%2;
			k=t/2;
	}
	k=0;//�ӷ���λ��־��ʼ��Ϊ0 
	for(i=8;i>=1;i--){//�ӷ����� 
	   	m=(a[i]+b[i]+k)%2;
	   	if(m==1)
	   	    move+=pow(2,8-i);
	   	k=(a[i]+b[i]+k)/2;
	}
	return move;
} 


int addOrder(bool a[]) {//�����1 
	int i,k=1,m;
	for(i=7;i>=0;i--){
		m=a[i]+k;
		a[i]=m%2;
		k=m/2;
	}
	return k;
}


float addfloat(bool float1[],bool float2[]){
	int i,j=0,flag=float1[0],max=0,move=0,m,k=0;//flagΪ���ű�־ moveΪ��λ 
//	int guard=0,round=0;//guardΪ����λ��roundΪ����λ 
	int a[27]={0};//����λ 0 1 ��β����a[25]����λ��a[26]����λ��
	bool *f1,*f2,w1[23]={0},w2[23]={0}; //w1�д�Ž���������β����w2�д�Ž���С������β�� 
	bool order[8]={0},b[32]={0}; //order�ڴ洢���� ,bΪ���ս�� 
	a[25]=0;a[26]=0;
	for(i=1;i<=9;i++){//�ж�����������Ĵ�С 
		if(float1[i]==float2[i]) continue;
		if(float1[i]>float2[i]){//float1 �����ʱ 
			max=1;
			break;
		}
		if(float1[i]<float2[i]){//float2 �����ʱ 
			max=2;
			break;
		}
	}
	//��ֵ�����f1�� ��Сֵ�����f2�� 
	if(max==1){  
		f1=float1;
		f2=float2;
    }
    else if(max==2){
    	
    	f1=float2;
		f2=float1;
	}
	
	for(i=1;i<9;i++) 
		order[i-1]=f1[i];
	
	move=subComplement(f1,f2);//������
	//����С������β�����ƶ�ʱ������λ��1Ҫһ���ƶ� 
	//��������ƶ�����µı���λ������λ��ֵ 
	if(move==1)
		a[25]=f2[n-1];
	else if(move>1&&move<=23){
		a[25]=f2[n-move];
		a[26]=f2[n+1-move];
	}
	else if(move==24){
		a[25]=1;
		a[26]=f2[0];
	}
	else if(move==25)
	    a[26]=1;
	
	for(i=9;i<n;i++){
		w1[j]=f1[i];
		j++;
	}

	j=22;//����ֵ0 
	if(move>=1&&move<=23){
		for(i=31-move;i>=9;i--){
			w2[j]=f2[i];
			j--;
		}
		w2[j]=1;//����λ��1 
	} 
	
	a[1]=1;//������β���е�����λ��1 
	for(i=24;i>=2;i--){
		m=w1[i-2]+w2[i-2]+k;
		a[i]=m%2;
		k=m/2;
	}
	m=a[1]+k;
	a[1]=m%2;
	a[0]=m/2;
	
	if(a[0]==1) {//����������ִ���1�������1 
	     addOrder(order);
     	for(i=26;i>0;i--)
     	     a[i]=a[i-1];
    	a[i]=0;///
    }
	
	//�ж�β�����ֵ��������
	//11ʱ��λ 00��01ʱ���� 
	//10 ʱǿ��β������Ϊż�� 
	k=1; 
	if((a[25]==1&&a[26]==1)||(a[25]==1&&a[26]==0&&a[24]==1)){
		for(i=24;i>=2;i--){
			m=a[i]+k;
			a[i]=m%2;
			k=m/2;
		}
		m=a[1]+k;
    	a[1]=m%2;
    	a[0]=m/2;
    	//���ܻ����β��+1�� �������ֽ�λ����� 
    	if(a[0]==1) {
	        addOrder(order);
         	for(i=26;i>0;i--)
	            a[i]=a[i-1];
         	a[i]=0;
         	if((a[25]==1&&a[26]==1)||(a[25]==1&&a[26]==0&&a[24]==1)){
	        	for(i=24;i>=2;i--){
      			m=a[i]+k;
	    		a[i]=m%2;
	    		k=m/2;
    	    	}
           }
    	}  
	} 
	b[0]=flag;
	j=1;
	for(i=0;i<8;i++){
		b[j]=order[i];
		j++;
	}
	for(i=2;i<=24;i++){
		b[j]=a[i];
		j++;
	}
//	printf("������Ϊ��"); 
	for(i=0;i<n;i++)
	   printf("%d",b[i]);
//	floatToValue(b);
	return 0;
}


int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout); 
	bool float1[n],float2[n];
	int i;
	for(i=0;i<n;i++)
		float1[i]=getchar()-'0';
	getchar();
	for(i=0;i<n;i++)
		float2[i]=getchar()-'0';
	getchar();
	addfloat(float1,float2);
	return 0;
}

#include<stdio.h> 
#include<stdbool.h> 
#include<math.h>
#define num 4 //num位的加减法运算 
bool OF=0,CF=0,SF=0,ZF=0; 

int addsub(bool int1[],bool int2[],bool flag){
	bool val[num+1]={0};
	int k=0,m=num,value=0,i,t,k0=0;
	if(flag==1){  //减法时计算后者的补码 
		for(i=num-1;i>=0;i--){
			t=int2[i]+1+k;
			int2[i]=(t+1)%2;
			k=t/2;
		}
	} 

	k=0;//加法进位标志初始化为0 
	for(i=num-1;i>=0;i--,m--){//加法运算 
	   	val[m]=(int1[i]+int2[i]+k)%2;
	   	k=(int1[i]+int2[i]+k)/2;
	   	if(i==1) k0=k;
	}
	val[m]=k;//溢出时的最高位 
	
	for(i=num;i>=1;i--){//计算无符号真值 
		if(val[i]==1) 
	    	value+=pow(2,num-i);
	}
	
	//求解ZF,OF,SF,CF
	if(value==0) ZF=1; 
	OF=val[0]^k0;// Cn异或Cn-1,k0为低位进位 
	SF=val[1];// 符号位为运算结果最高位 
	CF=flag^val[0];// Cout异或Cin
	return value;//返回为无符号结果 
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
	printf("Please choose sub(1) or add(0):");//flag为1 表示减法，flag为0 表示加法 
	flag=getchar()-'0';
	getchar();
	value_n=addsub(int1,int2,flag);
	printf("\nOF=%d,CF=%d,SF=%d,ZF=%d",OF,CF,SF,ZF);
	
	t=value_n;//
	for(i=0;i<num;i++){//将无符号真值转化为二进制存储在bool型数组中 
		if(t-pow(2,num-i-1)>=0) {
			v[i]=1;
			t-=pow(2,num-i-1);
		}
	}
	
	printf("\n机器数为：");
	for(i=0;i<num;i++)
		printf("%d",v[i]);
	
	if(v[0]==0) value_y=value_n;
	else{
		for(i=num-1;i>=0;i--){//二进制减一、取反 操作  
			t=v[i]+1+k;//数值加进位的和 
			v[i]=(t+1)%2;//取余为数值， +1进行取反操作 
			k=t/2;
		}
		for(i=1;i<num;i++)
		    if(v[i]==1) 
	    	    value_y+=pow(2,num-i-1);
	    value_y*=-1;
	}
		
	//无符号加溢出条件：CF=1 
	if(CF==1) printf("\n\nsum=%d\t无符号情况下，发生溢出",value_n);
	   else printf("\n\nsum=%d\t无符号情况下，未发生溢出",value_n);
	//带符号加溢出条件：OF=1 
	if(OF==1) printf("\nsum=%d\t有符号情况下，发生溢出",value_y);
	else printf("\nsum=%d\t有符号情况下，未发生溢出",value_y);
	return 0;
}

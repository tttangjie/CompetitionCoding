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
	int y=0,i,flag=0,t;//falg为借进位标志 
	for(i=0;i<32;i++) //copy操作 
	   bitv[i]=binary[i];
	if(bitv[31]==0){
		for(i=30;i>=0;i--)
			if(bitv[i]==1)
			    y+=pow(2,i);
		return y;
	}
	else
	{
		for(i=0;i<32;i++)//二进制减一、取反 操作  
		{
			t=bitv[i]+1+flag;//数值加进位的和 
			bitv[i]=(t+1)%2;//取余为数值， +1进行取反操作 
			flag=t/2;
		}
		for(i=30;i>=0;i--)
		    if(bitv[i]==1) 
	    	    y+=pow(2,i);
		return -y;
	}
}

//非规格化数0，阶码全为0，尾数任意 return 0；
//无穷大，阶码全为1，尾数部分全为0 return 1.#INF00
//NaN 阶码全为1，尾数部分不全为0   return 1.#QNAN0
float floatToValue(bool binary[])
{
	int sign=binary[31]==0?1:-1;//符号位 
	int i,k=0,num1=0,num2=0;//num1记录阶码内1的数量，num2记录尾数内1的数量 
	float value=1; 
	for(i=30;i>=23;i--)//阶码的真值 
	{
		if(binary[i]==1) 
		{
			num1++;
	    	k+=pow(2,i-23);
	    }
	}
	k-=127;//阶码-27为指数 
	for(i=22;i>=0;i--)//尾数部分的计算 
	{
		if(binary[i]==1){
		  num2++;
		  value+=pow(2,-1*(23-i));
     	}
	}
	if(num1==0&&num2==0)
	    printf("\n此浮点数为 0"); 
	else if(num1==8&&num2==0)
	    printf("\n此浮点数为 无穷大");
	else if(num1==8&&num2!=0)
	    printf("\n此浮点数为 非数"); 
	else printf("\n转化为浮点数：%.60f",sign*value*pow(2,k));
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
	printf("\n转化为无符号数：%u",unsignedToValue(binary));
	printf("\n转化为有符号数：%d",intToValue(binary));
    floatToValue(binary);
	return 0;
}

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define n 32

float floatToValue(bool binary[])
{
	int sign=binary[0]==0?1:-1;//符号位 
	int i,k=0,num1=0,num2=0;//num1记录阶码内1的数量，num2记录尾数内1的数量 
	float value=1; 
	for(i=1;i<=8;i++)//阶码的真值 
	{
		if(binary[i]==1) 
		{
			num1++;
	    	k+=pow(2,8-i);
	    }
	}
	k-=127;//阶码-27为指数 
	for(i=31;i>8;i--)//尾数部分的计算 
	{
		if(binary[i]==1){
		  num2++;
		  value+=pow(2,-1*(i-8));
     	}
	}
	if(num1==0&&num2==0)
	    printf("\n此浮点数为 0"); 
	else if(num1==8&&num2==0)
		printf("\n此浮点数为 无穷大");
	else if(num1==8&&num2!=0)
		printf("\n此浮点数为 非数"); 
	else printf("\n转化为浮点数：%.20f",sign*value*pow(2,k));
	return sign*value*pow(2,k);
}


int subComplement(bool a[],bool b[]) {//补码相减 
    int i,k=0,t,m,move=0;
	for(i=8;i>=1;i--){//计算被减数b的阶码的补码 
			t=b[i]+1+k;
			b[i]=(t+1)%2;
			k=t/2;
	}
	k=0;//加法进位标志初始化为0 
	for(i=8;i>=1;i--){//加法运算 
	   	m=(a[i]+b[i]+k)%2;
	   	if(m==1)
	   	    move+=pow(2,8-i);
	   	k=(a[i]+b[i]+k)/2;
	}
	return move;
} 


int addOrder(bool a[]) {//阶码加1 
	int i,k=1,m;
	for(i=7;i>=0;i--){
		m=a[i]+k;
		a[i]=m%2;
		k=m/2;
	}
	return k;
}


float addfloat(bool float1[],bool float2[]){
	int i,j=0,flag=float1[0],max=0,move=0,m,k=0;//flag为符号标志 move为移位 
//	int guard=0,round=0;//guard为保护位，round为舍入位 
	int a[27]={0};//隐藏位 0 1 ，尾数，a[25]保护位和a[26]舍入位。
	bool *f1,*f2,w1[23]={0},w2[23]={0}; //w1中存放阶码大的数的尾数，w2中存放阶码小的数的尾数 
	bool order[8]={0},b[32]={0}; //order内存储阶码 ,b为最终结果 
	a[25]=0;a[26]=0;
	for(i=1;i<=9;i++){//判断两个数阶码的大小 
		if(float1[i]==float2[i]) continue;
		if(float1[i]>float2[i]){//float1 阶码大时 
			max=1;
			break;
		}
		if(float1[i]<float2[i]){//float2 阶码大时 
			max=2;
			break;
		}
	}
	//大值存放在f1中 ，小值存放在f2中 
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
	
	move=subComplement(f1,f2);//求阶码差
	//阶码小的数的尾数在移动时，隐藏位的1要一起移动 
	//计算各种移动情况下的保护位和舍入位的值 
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

	j=22;//赋初值0 
	if(move>=1&&move<=23){
		for(i=31-move;i>=9;i--){
			w2[j]=f2[i];
			j--;
		}
		w2[j]=1;//隐藏位的1 
	} 
	
	a[1]=1;//阶码大的尾数中的隐藏位的1 
	for(i=24;i>=2;i--){
		m=w1[i-2]+w2[i-2]+k;
		a[i]=m%2;
		k=m/2;
	}
	m=a[1]+k;
	a[1]=m%2;
	a[0]=m/2;
	
	if(a[0]==1) {//如果整数部分大于1，阶码加1 
	     addOrder(order);
     	for(i=26;i>0;i--)
     	     a[i]=a[i-1];
    	a[i]=0;///
    }
	
	//判断尾数部分的舍入情况
	//11时进位 00，01时舍弃 
	//10 时强制尾数部分为偶数 
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
    	//可能会出现尾数+1后 整数部分进位的情况 
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
//	printf("计算结果为："); 
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

#include<stdio.h>
int check(int a)
{
	int n=0;
	while(a){
		if(a%10==4)
			n++;
		a/=10;
	}
	return n;
}

int main()
{
	int i,res=0;
	for(i=10000;i<=99999;i++){
		if(check(i)==0)
			res++;		
	}
	printf("%d",res);
	
	return 0;
 } 

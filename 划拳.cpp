#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a1,a2,b1,b2;
	int counta = 0,countb = 0; 
	int n,num = 0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		num = a1+b1;
		if((a2==num&&b2==num)||(a2!=num&&b2!=num))
			continue;
		else if(a2!=num)
			counta++;
		else
			countb++;		
	} 
	printf("%d %d\n",counta,countb);
	
	return 0;
}

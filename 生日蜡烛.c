#include<stdio.h>
int main()
{
	int num=0,i,start=1;
	for(i=1;num!=236;i++){
		if(num<236){
			num+=i;
			
		}
		else if(num>236){
			num-=start;
			start++;
			i--;
		}
	}
	printf("%d %d",start,i);
	
	return 0;
}

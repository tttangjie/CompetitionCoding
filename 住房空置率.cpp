#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int main()
{
	int counta = 0, countb = 0, count;
	int n, num, k, a, i;
	double rate, b;
	scanf("%d%lf%d",&n,&rate,&num);
	k = n;
	while(k--){
		count = 0;
		scanf("%d",&a);
		for(i=0;i<a;i++){
			scanf("%lf",&b);
			if(b<rate){
				count++;
			}
		}
		if(count>a/2 && a>num)
			countb++;
		else if(count>a/2 && a<=num)
			counta++;
	}
	printf("%.1lf%% %.1lf%%\n",(counta*1.0/n*1.0)*100,(countb*1.0/n*1.0)*100);
	
	
	
	return 0;
}

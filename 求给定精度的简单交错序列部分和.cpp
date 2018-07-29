#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<math.h>
#define N 100
int main()
{
	double sum = 0, x, eps,i = 1;
	int flag = 1;
	scanf("%lf",&eps);
	if(eps>=1)	sum = 1;
	else	
		while((1/i) >= eps){
			sum+=flag*1.0/i;
			i+=3;
			flag = -1*flag;
		}
	printf("sum = %.6lf\n",sum);
	return 0;
 } 

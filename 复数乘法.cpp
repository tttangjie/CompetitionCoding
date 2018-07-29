#include<stdio.h>
#include<math.h>

int main()
{
	double r1,p1,r2,p2;
	double a,b;
	scanf("%lf%lf%lf%lf",&r1,&p1,&r2,&p2);
	a = r1*r2*cos(p1)*cos(p2)-r1*r2*sin(p1)*sin(p2);
	b = r1*r2*cos(p1)*sin(p2)+r1*r2*sin(p1)*cos(p2);
	if(a>-0.005 && a<0)
		printf("0.00");
	else
		printf("%.2lf",a);
	if(b>-0.005 && b<0)
		printf("+0.00i\n");
	else if(b>=0)
		printf("+%.2lfi\n",b);
	else
		printf("%.2lfi\n",b);
	
	return 0;
}

#include<stdio.h>

int main()
{
	int counta = 0,countb = 0;
	int limita,limitb,n;
	int a1,a2,b1,b2;
	scanf("%d%d",&limita,&limitb);
	scanf("%d",&n);
	while((counta<limita+1 && countb<limitb+1)&& n--){
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		if (a1+b1 == a2 && a1+b1!=b2)
			counta++;
		else if (a1+b1 != a2 && a1+b1 == b2)
			countb++;
	}
	if(counta>limita)
		printf("A\n%d",countb);
	else
		printf("B\n%d",counta);
	return 0;
}

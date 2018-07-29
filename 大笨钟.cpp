#include<stdio.h>
#define N 12
void putsDang(int n){
	int i;
	for (i = 0;i < n;i++)
		printf("Dang");
}

int main()
{
	int hour,minute;
	scanf("%d:%d",&hour,&minute);
	if (hour>=0&&hour<12)
		printf("Only %02d:%02d.  Too early to Dang.",hour,minute);
	else if (hour == 12 && minute == 0)
		printf("Only %02d:%02d.  Too early to Dang.",hour,minute);
	else if(hour > 12 && minute == 0)
		putsDang(hour-N);
	else 
		putsDang(hour-N+1);
	return 0;
 } 

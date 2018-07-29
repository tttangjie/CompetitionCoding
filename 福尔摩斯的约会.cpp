#include<stdio.h>
#define N 61

int main()
{
	char a[N],b[N],c[N],d[N];
	int i,count = 0;
	int day,hour,minute;
	gets(a);
	gets(b);
	gets(c);
	gets(d);
	for(i = 0;a[i]&&b[i]&&count<2;i++){
		if(a[i] == b[i]&&count == 0&&a[i]>='A'&&a[i]<='G'){
			day = a[i] - 'A'+1;
			count++;
		}
		else if(a[i] == b[i]&&count == 1&&((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9'))){
			if(a[i]>='A'&&a[i]<='N')
				hour = a[i]-'A'+10;
			else
				hour = a[i]-'0';
			break;
		}
	}
	for(i = 0;c[i]&&d[i];i++){
		if(c[i] == d[i]&&((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z'))){
			minute = i;
			break;
		}
	}
	switch(day){
		case 1:printf("MON ");
			break;
		case 2:printf("TUE ");
			break;
		case 3:printf("WED ");
			break;
		case 4:printf("THU ");
			break;
		case 5:printf("FRI ");
			break;
		case 6:printf("SAT ");
			break;
		case 7:printf("SUN ");
			break;
	}
	printf("%02d:%02d\n",hour,minute);
	return 0;
}

#include<stdio.h>
void change(int sum)
{
	int i=0,j,m=sum,arr[5];
	while(m)
	{
		m/=10;
		i++; 
	}
	j=i-1;
	while(i)
	{
		arr[i-1]=sum%10;
		sum/=10;
		i--;
	}
	while(i!=(j+1))
	{
		switch(arr[i])
		{
			case 0:printf("ling");break;
			case 1:printf("yi");break;
			case 2:printf("er");break;
			case 3:printf("san");break;
			case 4:printf("si");break;
			case 5:printf("wu");break;
			case 6:printf("liu");break;
			case 7:printf("qi");break;
			case 8:printf("ba");break;
			case 9:printf("jiu");break;
		}
		if(i!=j) printf(" ");
		i++;
	}
}
main()
{
	char s[100],*k;
	int sum=0;
	scanf("%s",s);
	k=s;
	while(*k)
	{
		sum+=*k-'0';
		k++;
	}
	change(sum);
}

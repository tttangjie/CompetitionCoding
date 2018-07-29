#include<stdio.h>
int main()
{
	int total,n;
	int first,b,t,last;
	scanf("%d%d",&total,&n);
	while(n--&&total!=0)
	{
		scanf("%d%d%d%d",&first,&b,&t,&last);
		if(t>total)
			printf("Not enough tokens.  Total = %d.\n",total);
		else if(first>last&&b==0||first<last&&b==1) 
		{
			total+=t;
			printf("Win %d!  Total = %d.\n",t,total);
		}
		else if(first<last&&b==0||first>last&&b==1)
		{
			total-=t;
			printf("Lose %d.  Total = %d.\n",t,total);
		}
	}
	if(total==0) printf("Game Over.\n");	
	return 0;
 } 

#include<stdio.h>
#include<math.h>
int main()
{
	int max=0,i,left=0,j,temp;
	int N;
	scanf("%d",&N);
	for(i=2;i<=sqrt(N)+1;i++){
		if(N%i==0){
			temp=N/i;
			for(j=i+1;j<=sqrt(N)+1;j++){
				if(temp%j==0)
					temp/=j;
				else
					break;
			}
			if(j-i>max){
				max=j-i;
				left=i;
			}
		}
	}
	if(max==0){
		max=1;
		left=N;
	}
	printf("%d\n",max);
	printf("%d",left);
	for(i=left+1;i<left+max;i++){
		printf("*%d",i);
		}
	return 0;
 } 

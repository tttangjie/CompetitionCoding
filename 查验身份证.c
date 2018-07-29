#include<stdio.h>

int main()
{
	int flag=0,n,num=0,k=0,i,flag1=0;
	char c;
	char arr[18];
	int weigh[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	scanf("%d",&n);
	getchar();
	while(n--){
		num=0;
		k=0;
		c=getchar();
		flag1=0;
		while(c!='\n'){
			arr[k]=c;
			if(!(c>='0'&&c<='9')&&!(k==17&&c=='X'))
				flag1=1;
			k++;
			c=getchar();
		}
		if(flag1==0&&k==18){
			for(i=0;i<k-1;i++){
				num+=(arr[i]-'0')*weigh[i];
			}
		}

		if(M[num%11]!=arr[17]||flag1==1){
			for(i=0;i<k;i++){
				putchar(arr[i]);
			}
			if(n!=0)
				printf("\n");
			flag=1;
		}
	}
	if(flag==0)
		printf("All passed");
	
	return 0;
}

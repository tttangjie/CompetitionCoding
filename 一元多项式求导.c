#include<stdio.h>
#define N 10005

int main()
{
	
	int num[N],a[N],i=0,j=0,x,t=0;
	scanf("%d",&x);
		num[i]=x;
	while(getchar()!='\n')
	{   i++;
		scanf("%d",&x);
		num[i]=x;
	 } 
	 if(num[1]==0||num[0]==0){
	 	printf("0 0");
	 	return 0;
	 }
	 for(j=0;j<=i;j++)
	 {
//	 	if((j==1&&num[j]==0)||(j==0&&num[j]==0))
//	 {
//	 	printf("0 0");
//	 	return 0;
//	 }
	 	if(j==i-1&&num[j+1]==0) {
		 break;}
	 	if(j%2==0)
	 	{
	 		a[t]=num[j]*num[j+1];
	 		t++;
		 }
		 else{
		 	a[t]=num[j]-1;
		 	t++;
		 } 
   } 
   for(i=0;i<t;i++)
   {
   	printf("%d",a[i]);
   	if(i!=t-1) printf(" ");
   }
	return 0;
 } 

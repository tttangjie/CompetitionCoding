#include<stdio.h>
#define N 1003
int main()
{
	int arr[N],i=0,j,num[10]={0},count=0;
	char c=getchar();
	while(c!='\n'){
		arr[i]=c-'0';
		i++;
		c=getchar();
	}
	for(j=0;j<i;j++){
		num[arr[j]]++;
	}
	for(j=0;j<10;j++){
		if(num[j]!=0) count++;
	}
	for(i=0;i<10;i++){
		if(num[i]!=0){
			printf("%d:%d",i,num[i]); 
			count--;
		}
		if(count!=0&&num[i]!=0) printf("\n");
	}
	return 0;
}

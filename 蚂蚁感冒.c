#include<stdio.h>
#define N 50
int main()
{
	int n,t,i=0,flag=0,count=1;
	int a[N];
	scanf("%d",&n);
	t=n;
	while(t--){
		scanf("%d",&a[i]);
		i++;
	}
	if(a[0]>0){
		for(i=1;i<n;i++){
			if(a[i]<0&&a[i]*(-1)>a[0]){
				flag=1;
				count++;
			}
			if(a[i]>0&&a[i]<a[0]){
				count++;
			}
		}

	}
	if(a[0]<0){
		for(i=1;i<n;i++){
			if(a[i]>0&&a[i]<a[0]*(-1)){
				flag=1;
				count++;
			}
			if(a[i]<0&&a[i]*(-1)>a[0]*(-1)){
				count++; 
			}
		}

	}
	if(flag==0)
		printf("1");
	else
		printf("%d",count);
		
	return 0;
 } 

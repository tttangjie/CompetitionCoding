#include<stdio.h>
#define MAXSIZE 12
#define datetype int 

int binSearch(datetype a[],datetype x)
{
	int low,high,mid;
	low=0;
	high=MAXSIZE-1;
	while(low<=high){
		mid=(low+high)/2;
		if(x==a[mid]) return mid;
		if(x<a[mid])
			high=mid-1;
		else low=mid+1;
	}
	return -1;
}

int main()
{
	int i,k;
	datetype arr[MAXSIZE],key;
	for(i=0;i<MAXSIZE;i++)
	   scanf("%d",&arr[i]);
	scanf("%d",&key);
	k=binSearch(arr,key);
	if(k<0)  printf("未找到%d\n",key);
	else printf("%d为第%d个元素\n",key,k+1); 
	return 0;
 } 

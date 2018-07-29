#include<stdio.h>
//简单选择排序
//在待排记录中依次选择关键字最小的作为有序序列最后一条元素 
void selectSort(int a[]) {
	int i,j,k; //k记录最小元素的下标 
	for(i=1;i<10;i++)	{
		k=i;
		for(j=i+1;j<=10;j++)
			if(a[j]<a[k]) k=j;
		if(k!=i) {
			a[0]=a[i];
			a[i]=a[k];
			a[k]=a[0];
		}
	}
}

int main()
{
	int a[11]={0,6,9,5,2,3,4,7,8,1,0};
	int i;
	selectSort(a);
	for(i=1;i<=10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

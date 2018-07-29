#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 100000 
#define datetype int

void bucketSort(datetype a[]){
	int i,m=0;
	datetype t[MAXSIZE]={0};
	for(i=0;i<MAXSIZE;i++)
		t[a[i]]++;
	for(i=0;i<MAXSIZE;i++){
		while(t[i]){
		  	a[m++]=i;
		  	t[i]--;
		  }
	}
} 

int main()
{
	int i;
	clock_t start,finish;
	srand(time(NULL));
	datetype bus[MAXSIZE];
	for(i=0;i<MAXSIZE;i++)
	    bus[i]=rand()%MAXSIZE;
	start=clock();
	bucketSort(bus);
	finish=clock();
	printf("桶排序 实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
//	for(i=0;i<MAXSIZE;i++)
//	    printf("%d\t",bus[i]);
	return 0;
 } 

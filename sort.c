#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 10000
typedef int datetype;

//直接插入排序
//设立监视哨存储待排对象，从2开始到MAXSIZE
//按其关键码大小插入到前面 已排好序的适当位置 
void insertSort(datetype a[]){
	int i,j;
	for(i=2;i<MAXSIZE;i++){
		a[0]=a[i];//监视哨中存放数据 
		j=i-1;
		while(a[0]<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
}

//希尔排序 
//将整个待排对象序列分割成若干子序列，分别进行直接插入排序 
//将相隔某个增量记录成子序列，让dk逐趟缩短直到dk=1 
void shellSort(datetype a[],int d[]){
	int i,j,k=0,t;
	while(d[k]){//dk存放增量 
		j=1;//记录di组 
		while(j<=d[k]){
			for(i=d[k]+j;i<MAXSIZE;i+=d[k]){
	    		a[0]=a[i];
    			t=i-d[k];
     			while(a[0]<a[t]&&t>=0){
	    			a[t+d[k]]=a[t];
	    			t-=d[k];
    			}
	     		a[t+d[k]]=a[0];
	    	}//
	    	j++;
	    }
		k++;
	} 
}

//冒泡排序
//每段将对象两两比较，并按前小后大规则交换 
void bubbleSort(datetype a[]){ 
	int i,j,flag=1;
	for(i=1;(i<MAXSIZE-1)&&flag;i++){
		flag=0;
		for(j=MAXSIZE-2;j>=i;j--){
			if(a[j]>a[j+1]){
				a[0]=a[j];
				a[j]=a[j+1];
				a[j+1]=a[0];
				flag=1;
			}
		}
	}
}

//快速选择排序 
//树立一个旗杆，比他小的元素前放，比他大的元素后放
//最后剩余位置为旗杆排序后应在的位置
//左右两子表重新快排
void quickSort(datetype a[],int left,int right) {
	if(left>=right) return ;
	int low=left,high=right,temp=a[left];
	while(low<high)	{
		while(low<high&&a[high]>=temp)
		    high--;
		if(low<high){//找到小于标志位的元素 
			a[low]=a[high];//赋值给low下标位置 
			low++;//low下标后移 
		} 
		else break;//high位置右边元素都不小于标志位 
		
		while(low<high&&a[low]<temp)
		    low++;
		if(low<high){
			a[high]=a[low];
			high--;
		}
		else break;
	}
	a[low]=temp;	  //low==high时 标志位为已排好的序列号
	quickSort(a,left,low-1);
	quickSort(a,low+1,right); 
}

//简单选择排序
//在待排记录中依次选择关键字最小的作为有序序列最后一条元素 
void selectSort(datetype a[]) {
	int i,j,k;//k记录最小元素的下标 
	for(i=1;i<MAXSIZE;i++)	{
		k=i;
		for(j=i+1;j<MAXSIZE;j++)
			if(a[j]<a[k]) k=j;
		if(k!=i) {
			a[0]=a[i];
			a[i]=a[k];
			a[k]=a[0];
		}
	}
}

//堆排序

void heapSort(datetype a[]){
	
}

//归并排序 

void mergeSort(datetype a[]){
	
}

int main(){
	int i,n=4;
	datetype dk[21]={0},isr[MAXSIZE],bsr[MAXSIZE],ssr[MAXSIZE],qsr[MAXSIZE],Ssr[MAXSIZE],hsr[MAXSIZE],msr[MAXSIZE];
	clock_t start,finish;
	srand(time(NULL));
	
	
	for(i=1;i<MAXSIZE;i++)
		isr[i]=rand()%MAXSIZE;
	start=clock();//测量一个事件持续的时间 
	insertSort(isr);
	finish=clock();
	printf("直接插入排序 实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
		ssr[i]=rand()%MAXSIZE;
	i=0;
	while(n)//希尔排序 存储增量 
	{
		dk[i]=n;
		n/=2;
		i++;
	}
	start=clock();
	shellSort(ssr,dk);
	finish=clock();
	printf("希尔排序     实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for (i=1;i<MAXSIZE;i++)
	    bsr[i]=rand()%MAXSIZE;
	start=clock();
	bubbleSort(bsr);
	finish=clock();
	printf("冒泡排序     实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	     qsr[i]=rand()%MAXSIZE; 
	start=clock();
	quickSort(qsr,1,MAXSIZE-1);
	finish=clock();
	printf("快速排序     实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	     Ssr[i]=rand()%MAXSIZE;
	start=clock();
	selectSort(Ssr);
	finish=clock();
	printf("简单选择排序 实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	    hsr[i]=rand()%MAXSIZE;
	start=clock();
	heapSort(hsr);
	finish=clock();
	printf("堆排序       实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	    msr[i]=rand()%MAXSIZE;
	start=clock();
	mergeSort(msr);
	finish=clock();
	printf("归并排序     实际执行时间为：%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
//	for(i=1;i<MAXSIZE;i++){
//		printf("%d\t",Ssr[i]);
//	}
	return 0;
}

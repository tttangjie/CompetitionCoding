#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 10000
typedef int datetype;

//ֱ�Ӳ�������
//���������ڴ洢���Ŷ��󣬴�2��ʼ��MAXSIZE
//����ؼ����С���뵽ǰ�� ���ź�����ʵ�λ�� 
void insertSort(datetype a[]){
	int i,j;
	for(i=2;i<MAXSIZE;i++){
		a[0]=a[i];//�������д������ 
		j=i-1;
		while(a[0]<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
}

//ϣ������ 
//���������Ŷ������зָ�����������У��ֱ����ֱ�Ӳ������� 
//�����ĳ��������¼�������У���dk��������ֱ��dk=1 
void shellSort(datetype a[],int d[]){
	int i,j,k=0,t;
	while(d[k]){//dk������� 
		j=1;//��¼di�� 
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

//ð������
//ÿ�ν����������Ƚϣ�����ǰС�����򽻻� 
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

//����ѡ������ 
//����һ����ˣ�����С��Ԫ��ǰ�ţ��������Ԫ�غ��
//���ʣ��λ��Ϊ��������Ӧ�ڵ�λ��
//�������ӱ����¿���
void quickSort(datetype a[],int left,int right) {
	if(left>=right) return ;
	int low=left,high=right,temp=a[left];
	while(low<high)	{
		while(low<high&&a[high]>=temp)
		    high--;
		if(low<high){//�ҵ�С�ڱ�־λ��Ԫ�� 
			a[low]=a[high];//��ֵ��low�±�λ�� 
			low++;//low�±���� 
		} 
		else break;//highλ���ұ�Ԫ�ض���С�ڱ�־λ 
		
		while(low<high&&a[low]<temp)
		    low++;
		if(low<high){
			a[high]=a[low];
			high--;
		}
		else break;
	}
	a[low]=temp;	  //low==highʱ ��־λΪ���źõ����к�
	quickSort(a,left,low-1);
	quickSort(a,low+1,right); 
}

//��ѡ������
//�ڴ��ż�¼������ѡ��ؼ�����С����Ϊ�����������һ��Ԫ�� 
void selectSort(datetype a[]) {
	int i,j,k;//k��¼��СԪ�ص��±� 
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

//������

void heapSort(datetype a[]){
	
}

//�鲢���� 

void mergeSort(datetype a[]){
	
}

int main(){
	int i,n=4;
	datetype dk[21]={0},isr[MAXSIZE],bsr[MAXSIZE],ssr[MAXSIZE],qsr[MAXSIZE],Ssr[MAXSIZE],hsr[MAXSIZE],msr[MAXSIZE];
	clock_t start,finish;
	srand(time(NULL));
	
	
	for(i=1;i<MAXSIZE;i++)
		isr[i]=rand()%MAXSIZE;
	start=clock();//����һ���¼�������ʱ�� 
	insertSort(isr);
	finish=clock();
	printf("ֱ�Ӳ������� ʵ��ִ��ʱ��Ϊ��%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
		ssr[i]=rand()%MAXSIZE;
	i=0;
	while(n)//ϣ������ �洢���� 
	{
		dk[i]=n;
		n/=2;
		i++;
	}
	start=clock();
	shellSort(ssr,dk);
	finish=clock();
	printf("ϣ������     ʵ��ִ��ʱ��Ϊ��%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for (i=1;i<MAXSIZE;i++)
	    bsr[i]=rand()%MAXSIZE;
	start=clock();
	bubbleSort(bsr);
	finish=clock();
	printf("ð������     ʵ��ִ��ʱ��Ϊ��%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	     qsr[i]=rand()%MAXSIZE; 
	start=clock();
	quickSort(qsr,1,MAXSIZE-1);
	finish=clock();
	printf("��������     ʵ��ִ��ʱ��Ϊ��%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	     Ssr[i]=rand()%MAXSIZE;
	start=clock();
	selectSort(Ssr);
	finish=clock();
	printf("��ѡ������ ʵ��ִ��ʱ��Ϊ��%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	    hsr[i]=rand()%MAXSIZE;
	start=clock();
	heapSort(hsr);
	finish=clock();
	printf("������       ʵ��ִ��ʱ��Ϊ��%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	for(i=1;i<MAXSIZE;i++)
	    msr[i]=rand()%MAXSIZE;
	start=clock();
	mergeSort(msr);
	finish=clock();
	printf("�鲢����     ʵ��ִ��ʱ��Ϊ��%.10fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
//	for(i=1;i<MAXSIZE;i++){
//		printf("%d\t",Ssr[i]);
//	}
	return 0;
}

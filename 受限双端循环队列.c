//队头可以入队出队，队尾只能出队 
#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct
{
	int data[N];
	int front;//front指向第一个元素的前一个位置 
	int rear;//rear指向最后一个元素 
}sequeue;
void setNull(sequeue *sq)
{
	sq->front=N-1;
	sq->rear=N-1;
}
int InQueue(sequeue *sq,int x)
{
	if(sq->front==(sq->rear+1)%N)
	{
		printf("FULL\n");
		return 0;
	}
	else if(x<(sq->data[(sq->front+1)%N]+sq->data[sq->rear])/2)
	{
		sq->data[sq->front]=x;
		sq->front=(sq->front-1+10)%N;
	}
	else
	{
		sq->rear=(sq->rear+1)%N;
		sq->data[sq->rear]=x;
	}
	return 1;
}

int main()
{ 	
    int i,x;
	sequeue *sq=NULL;
	sq=(sequeue*)malloc(sizeof(sequeue));
	for(i=0;i<N;i++)
	{
	sq->data[i]=0;
	}
	setNull(sq);
	scanf("%d",&x);
	while(x>0)
	{
		InQueue(sq,x);
		scanf("%d",&x);
	}
	for(i=(sq->front+1)%N;sq->data[i]>0;i++)
	{
		i=i%N;
		printf("%d ",sq->data[i]);
	}
	return 0;
} 

#include<stdio.h>
#include<algorithm>
#define M 5 
#define N 2*M-1 
#define MaxInt 666666
using namespace std;
typedef struct Node
{
	int father;
	int lchild;
	int rchild;
	int value;
} Node;

Node a[N];
int num[M]={2,3,6,7,9};

bool compare(const Node &x,const Node &y)
{
	return x.value<y.value;
}

void init()
{
	int i;
	for(i=0;i<N;i++){
		if(i<N)
			a[i].value=num[i];
		else
			a[i].value=0;
		a[i].lchild=-1;
		a[i].rchild=-1;
		a[i].father=-1;
	}
 } 

void buildHTree()
{
	int i,j,min,x,y;
	for(j=0;j<N;j++){
		
	}
}

int main()
{
	init();
	return 0;
}

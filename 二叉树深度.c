#include<stdio.h> 
#include<stdlib.h>
#define maxsize 100
typedef  char datatype;
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}bitree;
bitree *creattree(){
	bitree *Q[maxsize];
	datatype ch;
	int front,rear;
	bitree *root,*s;
	root=NULL;//置空二叉树 
	front=1;	rear=0;//置空队列 
	ch=getchar();
	while(ch!='#')
	{
		s=NULL;
		if(ch!='@')
		{
			s=malloc(sizeof(bitree));
			s->data=ch;
			s->lchild=NULL;
			s->rchild=NULL;
		}
		rear++;
		Q[rear]=s;
		if(rear==1) root=s;
		else{
			if(s&&Q[front])
			{
				if(rear%2==0) Q[front]->lchild=s;
				else Q[front]->rchild=s;
			}
			if(rear%2==1) front++;
		}
		ch=getchar();
	}
	return root;
}

int max(int m,int n)
{
	return m>=n?m:n;
} 

int depth(bitree *t)
{
	int ldepth=0,rdepth=0;
	if(t==NULL) return 0;
	else
	{
		ldepth=depth(t->lchild);
		rdepth=depth(t->rchild);
		return max(ldepth,rdepth)+1;
	}
}

int main()
{
	bitree *root;
	root=creattree();
	printf("二叉树深度为：%d",depth(root)); 
	return 1; 
}

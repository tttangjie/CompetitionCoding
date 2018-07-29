#include<stdio.h> 
#include<stdlib.h>
#define maxsize 100
//输入必须为完全二叉树 
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
			s=(bitree*)malloc(sizeof(bitree));
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


int num_left(bitree *t)
{
	int num;
	if(t==NULL) return 0; 
	if(t->lchild==NULL&&t->rchild==NULL) return 0;
	else{
		if(t->lchild!=NULL) 
			num=num_left(t->lchild)+1;		   
		if(t->rchild!=NULL) 
	    	num=num+num_left(t->rchild);	
		return num;
	}
}

int main()
{
	bitree *root;
	root=creattree();
	printf("%d",num_left(root)); 
	return 1; 
}

#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef char datatype;
typedef struct node{
	datatype data;
	struct node *lchild,*rchild;
}bitree;

bitree *creattree()
{
	bitree *Q[maxsize];
	bitree *root=NULL,*s;
	char ch;
	int front=1,rear=0;
	ch=getchar();
	while(ch!='#'){
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
		else
		{
			if (Q[front]&&s){
				if(rear%2==0) Q[front]->lchild=s;
				else Q[front]->rchild=s;
		    }
			if(rear%2==1) front++;
		}
		ch=getchar();
	}
	return root;
}

//һ����ȫ����������˳���sa�У�sa.elem[1��sa.last]�洢����ֵ�� 
#include<stdio.h> 
#include<stdlib.h>
#define maxsize 100
typedef  char datatype;
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}bitree;
bitree *createtree(){
	bitree *Q[maxsize];
	datatype ch;
	int front,rear;
	bitree *root,*s;
	root=NULL;
	front=1;	rear=0;
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

void preorder(bitree *t)//ǰ����� 
{
	if(t!=NULL)
	{
		printf("%c\t",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(bitree *t)//������� 
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		printf("%c\t",t->data);
		inorder(t->lchild);
	} 
}

void postorder(bitree *t)//�������� 
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c\t",t->data);
	}
}
int main()
{
	bitree *root;
	root=createtree();
	printf("ǰ�������");
	preorder(root); 
	printf("\n");
	printf("���������");
	inorder(root); 
	printf("\n");
	printf("���������");
	postorder(root); 
	printf("\n");
	return 1; 
}

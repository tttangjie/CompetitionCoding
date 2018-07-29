#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef char datatype;
typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	datatype data;	
 }bitree;
 bitree *creatnode(datatype a)
 {
 	bitree *s=NULL;
	 s=(bitree*)malloc(sizeof(bitree));
 	s->data=a;
 	s->lchild=NULL;
 	s->rchild=NULL;
 	return s;
 }
 bitree *createtree()
 {
 	bitree *sa[maxsize]={NULL};
 	int i=0,j;
 	datatype ch;
 	ch=getchar(); 
 	while(i<maxsize&&ch!='#'){
 		i++;
 		sa[i]=creatnode(ch);
 		ch=getchar();
	 }
	 for(j=1;j<=i/2;j++)
	 {
	 	sa[j]->lchild=sa[2*j];
	 	sa[j]->rchild=sa[2*j+1];
	 }
	 return sa[1];
 }
 void preorder(bitree *t)
{
	if(t!=NULL)
	{
		printf("%c\t",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
 int main()
 {
 	bitree *t=NULL;
	t=createtree();
	printf("Ç°Ğò±éÀú:"); 
	preorder(t);
	return 1;
 }

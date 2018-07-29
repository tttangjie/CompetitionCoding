#include<stdio.h> 
#include<stdlib.h>
typedef struct link
{
	char data;
	struct link *next;
}LINK;
LINK *node()
{
	LINK *head=NULL,*p,*rear;
	char ch;
	head=(LINK*)malloc(sizeof(LINK));
	printf("input ch till ch!=@\n");
	ch=getchar();
	rear=p=head;
	while(ch!='@')
	{
		p=(LINK*)malloc(sizeof(LINK));
		p->data=ch;
		rear->next=p;
		rear=p;
		ch=getchar();
	}
	rear->next=NULL;
	return head;
}
LINK* insert(LINK *s,LINK *t,char ch)
{
	LINK *p,*q,*l;
	p=t;
	q=t->next;
	if(q==NULL) return s;
	p=q;
	q=q->next;
	while(q)
	{
		if(p->data==ch)
		break;
		p=q;
		q=q->next;
	 } 
	if(q==NULL){
		p->next=s->next;
		return t;
	}
	l=s;
	while(l->next)
	{
		l=l->next;
	}
	p->next=s->next;
	l->next=q;
	return t;
}
int main()
{
	LINK *h1=NULL,*h2=NULL,*head=NULL,*p;
	h1=node();
	getchar();
	h2=node();
	getchar();
	char ch;
	printf("input ch:");
	ch=getchar();
	head=insert(h1,h2,ch);
	p=head->next;
	while(p){
		putchar(p->data);
		p=p->next;
	}
	return 0;
}


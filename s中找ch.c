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

LINK* del(LINK *h,int i,int k)
{
	LINK *p,*q; 
	int x=0;
	p=h;
	q=h->next;
	if(i!=x&&q)
	{
		p=q;
		q=q->next;
		x++;
	}
	if(q->data=='\0')return h;
	while(k--&&q)
	{
		p->next=q->next;
		free(q);
		q=p->next;
	}
	return h;
 } 

int main()
{
	LINK *h=NULL,*p,*head=NULL;
	int i,k;
	h=node();
	printf("input LOC_i,LEN_k\n");
	scanf("%d%d",&i,&k);
	head=del(h,i,k);
	p=h->next;
	while(p){
		putchar(p->data);
		p=p->next;
	}
	return 0;
}

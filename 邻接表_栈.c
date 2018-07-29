#include<stdio.h>
#include<stdlib.h>
#define E 5//6���� 
#define N 5//5������ 
typedef struct node {
	int  adjvex;//�ٽӵ���
	struct node *next; 
}edgenode;
typedef struct {
	char vertex;
	edgenode *link;
	int visited; 
}vexnode;
void creat(vexnode *ga){
	int i,j,k;
	edgenode *s=NULL;
	for(k=0;k<N;k++)//��ʼ�� 
	{
		ga[k].link=NULL;
	}
	for(k=0;k<E;k++)//��Ϊ������ͼ������Ҫi����j ��j����i 
	{
		scanf("%d%d",&i,&j);//��ʾi��j֮��������
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=j;
		s->next=ga[i].link;
		ga[i].link=s;
			
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=i;
		s->next=ga[j].link;
		ga[j].link=s;
		
    }
}
int find(vexnode *ga,int start,int end,int step){
	int i,j,k,top=0;
	edgenode *stack[N];//��ʼ��ջ 
	edgenode *p=NULL;
	 for(i=0;i<N;i++)//��ʼ����ȫ������Ϊû�б����ʹ� 
	  ga[i].visited=0;

	ga[start].visited = 1;//��ʾ�����ʹ��� 
	p=ga[start].link;
	if(p==NULL)
	   return 0;// ��Ϊû��·�����Բ����ܿ����ҵ� 
	stack[top++]=p;//��һ���ڵ���ջ
	p=ga[p->adjvex].link;
	while(top!=0)
	{
	   while(p==NULL&&ga[p->adjvex].visited==1)//Ѱ����һ��û�б��������Ľڵ� 
	   {
	   	  p=p->next;
	   }
	   if(p!=NULL)//��ʾ�ҵ��˽ڵ� 
	   {
	   	  if(p->adjvex==end&&top+1==step) 
		     return 1;
		  if(p->adjvex==end&&top+1!=step||p->adjvex!=end&&top+1==step)//����������
		  {
		  	   p=p->next; 
			   continue; 
		  } 
	   	  stack[top++]=p;//��ջ 
		  ga[p->adjvex].visited=1;//���Ϊ�Ѿ����ʹ��Ľڵ�
		  p=ga[p->adjvex].link;//������һ��	
	   }
	   else//��ʾû�нڵ���Է��� ����ô��ջ 
	   {
	   	   p=stack[--top];//��ջ 
	   	   ga[p->adjvex].visited=0;
	   	   p=p->next;//������һ�㣬����p֮���һ��	   
	   }
    }	  
    return 0; 
}
int main(){ 
    vexnode ga[N];
    int start,end,step,flag;
    creat(ga);
    printf("������start��end��setp\n");
    scanf("%d%d%d",&start,&end,&step);
    flag=find(ga,start,end,step);
    if(flag==1)
      printf("YES");
    else
      printf("NO");
   
	return 0;
}

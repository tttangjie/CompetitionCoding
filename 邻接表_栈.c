#include<stdio.h>
#include<stdlib.h>
#define E 5//6条边 
#define N 5//5个定点 
typedef struct node {
	int  adjvex;//临接点域
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
	for(k=0;k<N;k++)//初始化 
	{
		ga[k].link=NULL;
	}
	for(k=0;k<E;k++)//因为是无向图，所以要i连接j ，j连接i 
	{
		scanf("%d%d",&i,&j);//表示i和j之间有连接
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
	edgenode *stack[N];//初始化栈 
	edgenode *p=NULL;
	 for(i=0;i<N;i++)//初始化，全部设置为没有被访问过 
	  ga[i].visited=0;

	ga[start].visited = 1;//表示被访问过了 
	p=ga[start].link;
	if(p==NULL)
	   return 0;// 因为没有路，所以不可能可以找到 
	stack[top++]=p;//第一个节点入栈
	p=ga[p->adjvex].link;
	while(top!=0)
	{
	   while(p==NULL&&ga[p->adjvex].visited==1)//寻找下一个没有被遍历过的节点 
	   {
	   	  p=p->next;
	   }
	   if(p!=NULL)//表示找到了节点 
	   {
	   	  if(p->adjvex==end&&top+1==step) 
		     return 1;
		  if(p->adjvex==end&&top+1!=step||p->adjvex!=end&&top+1==step)//不符合条件
		  {
		  	   p=p->next; 
			   continue; 
		  } 
	   	  stack[top++]=p;//入栈 
		  ga[p->adjvex].visited=1;//标记为已经访问过的节点
		  p=ga[p->adjvex].link;//查找下一个	
	   }
	   else//表示没有节点可以访问 ，那么出栈 
	   {
	   	   p=stack[--top];//出栈 
	   	   ga[p->adjvex].visited=0;
	   	   p=p->next;//返回上一层，遍历p之后的一个	   
	   }
    }	  
    return 0; 
}
int main(){ 
    vexnode ga[N];
    int start,end,step,flag;
    creat(ga);
    printf("请输入start，end，setp\n");
    scanf("%d%d%d",&start,&end,&step);
    flag=find(ga,start,end,step);
    if(flag==1)
      printf("YES");
    else
      printf("NO");
   
	return 0;
}

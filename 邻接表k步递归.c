#include<stdio.h>
#include<stdlib.h>
#define n 5 //图的顶点数 
#define e 6 //图的边数
typedef char vextype;//顶点的数据类型
typedef int adjtype;//权值类型
typedef struct node{
	int adjvex;//存放与此节点相邻的点的点序号 
	adjtype arc;//权值 
	struct node *next;//将邻接表所有的表链接在一起 
}edgenode;//边表节点 
typedef struct{
	vextype vertex;//顶点信息
	edgenode *link;// 边表头指针 
}vexnode;//顶点表节点
vexnode ga[n];
void creatGraphList()
{
	int i,j,k,w;
	edgenode *s;
	for(i=0;i<n;i++)//录入顶点信息 
	{
		ga[i].vertex=getchar();
		ga[i].link=NULL;
	}
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&j,&k,&w);
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=j;//与i相邻的节点j 
		s->arc=w;
		s->next=ga[k].link;
		ga[k].link=s;//s插入顶点的 边表头部
		
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=k;
		s->arc=w;
		s->next=ga[j].link;
		ga[j].link=s;
	}
 } 
 int visited[n]={0};
int seekPath(int i,int j,int k)
 {
 	edgenode *p;
 	int m;
 	if(i==j&&k==0) return 1;
 	else if(k>0)
 	{
 		visited[i]=1;
 		for(p=ga[i].link;p;p=p->next)
 		{
 			m=p->adjvex;
 			if(visited[m]==0)
 			{
 			   if(seekPath(m,j,k-1)!=0)
 			   {
 			        return 1;
 			    }
 			}
		 }
		 visited[i]=0;
	 }
 	return 0;//未找到
  } 
 
 int main()
 {
 	creatGraphList();
 	if(seekPath(0,4,4))
 	printf("Yes\n");
 	else
 	printf("No\n");
 	return 1;
 }

#include<stdio.h>
#include<stdlib.h>
#define n 5 //图的顶点数 
#define e 5 //图的边数
typedef char vextype;//顶点的数据类型
typedef int adjtype;//权值类型
typedef struct{
	vextype vexs[n];//顶点信息 
	adjtype arcs[n][n];//两点权值 
}graph;

graph *creatGraph()//建立一个无向图 
{
	graph *gr=(graph*)malloc(sizeof(graph));
	int i,j,k;
	int w;//权值
	for(i=0;i<n;i++)
	{
		gr->vexs[i]=getchar();
	} 
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    gr->arcs[i][j]=0;
	 for(k=0;k<e;k++)
	 {
	 	scanf("%d%d%d",&i,&j,&w);
	 	gr->arcs[i][j]=w;
	 	gr->arcs[j][i]=w;
	 }
	 return gr;
 } 
 int visited[n]={0}; 
 void dfs(graph *gr,int i)//深度优先遍历
 {
 	putchar(gr->vexs[i]);//输出 节点信息 
 	visited[i]=1;//标记已访问 
 	int j;
 	for(j=0;j<n;j++)
 	    if(gr->arcs[i][j]!=0&&visited[j]==0)
 	        dfs(gr,j);
 }
 
 void bfs(graph *gr,int k)//广度优先遍历
 {
 	putchar(gr->vexs[k]);//输出节点信息 
 	int visited[n]={0};
	visited[k]=1;
	int Q[n]={k};
	int i,j=1,top=-1;
	while(top!=n)
	{
		top++;
		for(i=0;i<n;i++)
			if(gr->arcs[Q[top]][i]!=0&&visited[i]==0)
			{
				Q[j++]=i;
				putchar(gr->vexs[i]);
				visited[i]=1;
			}
	}
  } 
 int main()
 {
 	graph *gr=NULL;
 	gr=creatGraph();
 	printf("深度优先遍历："); 
 	dfs(gr,0);
 	printf("\n广度优先遍历：");
 	bfs(gr,0);
 	return 1;
  } 

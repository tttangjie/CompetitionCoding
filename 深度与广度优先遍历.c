#include<stdio.h>
#include<stdlib.h>
#define n 5 //ͼ�Ķ����� 
#define e 5 //ͼ�ı���
typedef char vextype;//�������������
typedef int adjtype;//Ȩֵ����
typedef struct{
	vextype vexs[n];//������Ϣ 
	adjtype arcs[n][n];//����Ȩֵ 
}graph;

graph *creatGraph()//����һ������ͼ 
{
	graph *gr=(graph*)malloc(sizeof(graph));
	int i,j,k;
	int w;//Ȩֵ
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
 void dfs(graph *gr,int i)//������ȱ���
 {
 	putchar(gr->vexs[i]);//��� �ڵ���Ϣ 
 	visited[i]=1;//����ѷ��� 
 	int j;
 	for(j=0;j<n;j++)
 	    if(gr->arcs[i][j]!=0&&visited[j]==0)
 	        dfs(gr,j);
 }
 
 void bfs(graph *gr,int k)//������ȱ���
 {
 	putchar(gr->vexs[k]);//����ڵ���Ϣ 
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
 	printf("������ȱ�����"); 
 	dfs(gr,0);
 	printf("\n������ȱ�����");
 	bfs(gr,0);
 	return 1;
  } 

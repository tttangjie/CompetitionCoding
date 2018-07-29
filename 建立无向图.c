#include<stdio.h>
#include<stdlib.h>
#define n 5 //图的顶点数 
#define e 8 //图的边数
typedef char vextype;//顶点的数据类型
typedef int adjtype;//权值类型
typedef struct{
	vextype vexs[n];
	adjtype arcs[n][n];
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
	    gr->arcs[i][j]=10000;
	 for(k=0;k<e;k++)
	 {
	 	scanf("%d%d%d",&i,&j,&w);
	 	gr->arcs[i][j]=w;
	 	gr->arcs[j][i]=w;
	 }
	 return gr;
 } 
 
 int main()
 {
 	graph *gr=NULL;
 	int i,j;
 	gr=creatGraph();
 	printf("\t");
 	for(i=0;i<n;i++)
 	   printf("%c\t",gr->vexs[i]);
 	printf("\n");
 	for(i=0;i<n;i++){
 		printf("%c\t",gr->vexs[i]);
		for(j=0;j<n;j++)
		{
		printf("%d\t",gr->arcs[i][j]);
		}
 	printf("\n");
    }
 	return 1;
  } 

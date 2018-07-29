#include<stdio.h>
#include<stdlib.h>
#define n 5 //ͼ�Ķ����� 
#define e 6 //ͼ�ı���
typedef char vextype;//�������������
typedef int adjtype;//Ȩֵ����
typedef struct node{
	int adjvex;//�����˽ڵ����ڵĵ�ĵ���� 
	adjtype arc;//Ȩֵ 
	struct node *next;//���ڽӱ����еı�������һ�� 
}edgenode;//�߱�ڵ� 
typedef struct{
	vextype vertex;//������Ϣ
	edgenode *link;// �߱�ͷָ�� 
}vexnode;//�����ڵ�
vexnode ga[n];
void creatGraphList()
{
	int i,j,k,w;
	edgenode *s;
	for(i=0;i<n;i++)//¼�붥����Ϣ 
	{
		ga[i].vertex=getchar();
		ga[i].link=NULL;
	}
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&j,&k,&w);
		s=(edgenode*)malloc(sizeof(edgenode));
		s->adjvex=j;//��i���ڵĽڵ�j 
		s->arc=w;
		s->next=ga[k].link;
		ga[k].link=s;//s���붥��� �߱�ͷ��
		
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
 	return 0;//δ�ҵ�
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

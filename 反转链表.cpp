#include<stdio.h>
#define N 1000

struct node{
	int add;
	int data;
	int next;
};

int main()
{
	struct node a[N],b[N],tmp;
	int start,num,k;
	int i,j,m,n,o;
	scanf("%d%d%d",&start,&num,&k);
	for(i = 0;i < num;i++){
		scanf("%d%d%d",&m,&n,&o);
		a[m].add = m;
		a[m].data = n;
		a[m].next = o;
	}
	b[0] = a[start];
	n = 1;i = 0;
	while(b[i].next!=-1){
		n++;i++;
		b[i] = a[ b[i-1].next ];
	}
	i = 0;
	while(i+k<=n){
		for(j = 0;j < k/2;j++){
			tmp = b[i+j];
			b[i+j] = b[i+k-j-1];
			b[i+k-j-1] = tmp;
		}
		i+=k;
	}
	for( i = 0;i<n-1;i++){
		printf("%05d %d %05d\n",b[i].add,b[i].data,b[i+1].add);
	}
	printf("%05d %d -1\n",b[i].add,b[i].data);
	return 0;
}

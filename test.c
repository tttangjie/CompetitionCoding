#include <stdio.h>
#include <malloc.h>
#define N 8
typedef struct node {
	int item;
	struct node *l;
	struct node *r;
}*link;
link *h;
int Nq=N;
link NODE(intitem,linkl,linkr) {
	link t=malloc(sizeof*t);
	t->l=l;
	t->r=r;
	t->item=item;
	return t;
}
void shif_up(inti) {
	int j;
	while(i>1) {
		j=i/2;
		if()
		}
}
void insert(linkt) {
	h[++Nq]=t;
	shif_up(Nq);
}
link delmin() {
	swap(1,Nq--);
	shif_down(1,Nq);
	return h[Nq+1];
}
link creat_heap(intfreq,intlen) {
	int i;
	for(i=0; i<len; i++)
		h[i]=NODE(freq[i],NULL,NULL);
	for(i=N/2; i>=0; i--)
		shif_down(i,N);
}
void huffman(intfreq[],intlen) {
	h=malloc(len*sizeof(link));
	creat_heap(h,freq,len);
	while(Nq>1) {
		linkt1=delmin();
		linkt2=delmin();
		insert(NODE(t1->item+t2->item,t1,t2));
	}
}
int main(void) {
	int freq[N]= {5,29,7,8,14,23,3,11};
	huffman(freq,N);
	return 0;
}

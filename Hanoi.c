#include<stdio.h>

char mark[3]={'A','B','C'};
int Hanoi(int n,char start,char end){
	char temp;
	int i;
	if(n==1){
		printf("%d :%c->%c\n",n,start,end);
		return 0;
	}
	for(i=0;i<3;i++){
		if(mark[i]!=start&&mark[i]!=end){
			temp=mark[i];
			break;
		}
	}
	Hanoi(n-1,start,temp);
	printf("%d :%c->%c\n",n,start,end);
	Hanoi(n-1,temp,end);
//	return -1;
}

int main()
{
	Hanoi(4,'A','C');
	return 0;
 } 

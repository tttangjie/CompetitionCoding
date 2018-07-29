#include<stdio.h>
int i=0;//移动次数 
void move(int n,char from,char to)//从下至上第n个元素的移动 
{
	i++;
	printf("第%d步：%d号元素 %c-->%c\n",i,n,from,to);
}
 
void Hanoi(int n,char x,char y,char z)//元素从x移至z 
{
	if(n==1)
	move(1,x,z);
	else{
		Hanoi(n-1,x,z,y);
		move(n,x,z);
		Hanoi(n-1,y,x,z);
	}
}
int main()
{
	Hanoi(4,'A','B','C');
	printf("共进行%d次移动\n",i);
	return 1;
}

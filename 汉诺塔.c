#include<stdio.h>
int i=0;//�ƶ����� 
void move(int n,char from,char to)//�������ϵ�n��Ԫ�ص��ƶ� 
{
	i++;
	printf("��%d����%d��Ԫ�� %c-->%c\n",i,n,from,to);
}
 
void Hanoi(int n,char x,char y,char z)//Ԫ�ش�x����z 
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
	printf("������%d���ƶ�\n",i);
	return 1;
}

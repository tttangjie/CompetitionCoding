#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 101

int main()
{
	char a[N],b[N],res[N],tmp[3]={'J','Q','K'};
	int lena,lenb,count = 0,i = 0,num = 0,j,k;
	scanf("%s%s",a,b);
	lena = strlen(a)-1;
	lenb = strlen(b)-1;
	while(lena>=0&&lenb>=0){
		count++;
		if(count%2){
			num = ((a[lena]-'0')+(b[lenb]-'0'))%13;
			if(num<10)
				res[i] = num+'0';
			else
				res[i] = tmp[num-10];
		} else{
			num = (b[lenb]-'0')-(a[lena]-'0');
			if(num<0)
				num+=10;
			res[i] = num+'0';
		}
		i++;
		lena--;
		lenb--;
	} 
	if(lena<0&&lenb>=0){
		for(j=lenb;j>=0;j--,i++){
			res[i] = b[j];
		}
	}
	if(lenb<0&&lena>=0){
		for(j=lena;j>=0;j--,i++){
			count++;
			if(count%2)
				res[i] = a[j];
			else{
				if(a[j]!='0'){
					num = 10 - (a[lena]-'0');
					res[i] = num+'0';
				}
				else 
					res[i] = a[j];
			} 
		}
	}
	for(j=i-1;j>=0;j--)
		putchar(res[j]);
	printf("\n");
	
	return 0;
} 

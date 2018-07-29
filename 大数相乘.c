#include<stdio.h>
#include<String.h>
#define M 10001
#define N 20005
int s[N]={0};
void mul(char a[],char b[])
{
	int t;
	char temp;
	int len_a,len_b,i,j,k=0,m;
	len_a=strlen(a);
	len_b=strlen(b);
	for(i=0;i<len_a/2;i++){
		temp=a[i];
		a[i]=a[len_a-i-1];
		a[len_a-i-1]=temp;
	}
	for(i=0;i<len_b/2;i++){
		temp=b[i];
		b[i]=b[len_b-i-1];
		b[len_b-i-1]=temp;
	}
	for(i=0;i<len_a;i++){
		for(j=0;j<len_b;j++)
			s[i+j]+=(a[i]-'0')*(b[j]-'0');
	}
	for(i=0;i<len_a+len_b-1;i++){
		m=s[i]+k;
		s[i]=m%10;
		k=m/10;
	}
	if(k!=0){
		m=s[i]+k;
		s[i]=m%10;
		k=m/10;
		i++;
	}
	while(k){
		s[i]=k%10;
		k/=10;
		i++; 
	}
	for(j=0;j<i/2;j++){
		t=s[j];
		s[j]=s[i-j-1];
		s[i-j-1]=t;
	}
	s[i]=-1;
}
 
int main()
{
	char a[M]={'0'},b[M]={'0'};
	int i=0;
	gets(a);
	gets(b);
	mul(a,b);
	while(s[i]==0)
		i++;
	if(s[i]==-1) printf("0"); 
	while(s[i]!=-1){
		printf("%d",s[i]);
		i++;
	}
	return 0;
 } 

#include<stdio.h>
#include<math.h>
#define N 100
typedef struct{
	int a;
	int b;
}fen;
int gcd(int a,int b)
{
	int t;
	while(a%b!=0){
		t=a;
		a=b;
		b=t%b;
	}
	return b;
}
int main()
{
	fen arr[N],res;
	int num=0,n,k=0,i,t,x,y;
	scanf("%d",&n);
	while(n--){
		scanf("%d/%d",&arr[k].a,&arr[k].b);
		t=gcd(arr[k].a,arr[k].b);
		if(t!=1){
			arr[k].a=arr[k].a/t;
			arr[k].b=arr[k].b/t;
		}
		if(abs(arr[k].a)>=arr[k].b){
			num+=arr[k].a/arr[k].b;
			arr[k].a=arr[k].a%arr[k].b;
		}
	//	printf("%d %d n:%d\n",arr[k].a,arr[k].b,num);
		k++;
	}
	res.a=arr[0].a;
	res.b=arr[0].b;
	for(i=1;i<k;i++){
		if(arr[i].a==0)
			continue;
		if(res.a==0){
			res.a=arr[i].a;
			res.b=arr[i].b;
			continue;
		}
		x=(res.a*arr[i].b)+(res.b*arr[i].a);
		y=(res.b)*(arr[i].b);
	//	printf("%d %d\n",res.a,res.b);
	//	printf("%d %d\n",arr[i].a,arr[i].b);
	//	printf("%d %d\n",x,y);

		t=gcd(x,y);
//		printf("%d\n",t);
		if(t!=1){
			x=x/t;
			y=y/t;
		}
		res.a=x;
		res.b=y;
		if(abs(x)>=y){
			num+=x/y;
			res.a=x%y;
			res.b=y;
		}
	}
	if(num==0&&res.a==0)
		printf("0");
	else if(num==0&&res.a!=0)
		printf("%d/%d",res.a,res.b);
	else if(num!=0&&res.a==0)
		printf("%d",num);
	else 
		printf("%d %d/%d",num,res.a,res.b);
	return 0;
 } 

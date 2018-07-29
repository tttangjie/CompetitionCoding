#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 1000
int main()
{
	int n, t = 1, k = -1;
	int a[N];
	int count = 0;
	int res = 0;
	scanf("%d",&n);
	
	while(t<n){
		t = t*10 +1;
		res++;
	}
	while(k != 0) {
		a[count] = t/n;
		k = t%n;
		t = k*10+1;
		count ++;	
		res++;
	}
	
	for(int i = 0; i<count; i++){
		printf("%d",a[i]);
	}
	printf(" %d\n",res);
	return 0;
 } 

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct str{
	char s[11];
	int num;
}a[11];

bool cmp(struct str a,struct str b){
	if(a.num>b.num) return true;
	return false;
}

int main()
{
	int T,n,i=0;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		getchar();
		for(i=0;i<11;i++){
			a[i].num=0;
		}
		i=0;
		while(n--){
			scanf("%s %d",a[i].s,&a[i].num);
			i++;
		}
		sort(a,a+11,cmp);
		i=0;
		while(a[i].num!=0){
			printf("%s",a[i].s);
			i++;
			if(a[i].num!=0)
				printf(" ");
		}
		printf("\n");
		
	}
	
	return 0;
}

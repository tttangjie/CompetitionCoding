#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 100

int main()
{
	int n, i, j = 0, k = 0, t = 0;
	char s[N], arr[N][5];
	int exc[5], num[3] = {0}, flag;
	memset(arr,0,sizeof(arr));
	for(i=0;i<3;i++){
		memset(s,0,sizeof(s));
		gets(s);
		while(s[j]!='\0'){
			if(s[j] == '['){
				j++; 
				while(s[j]!=']'){
					arr[k][t] = s[j];
					j++;t++;
				}
				k++;
				arr[k][t] = '\0';
				t = 0; 
				num[i]++;
			}
			j++; 
		}
		j = 0;
	}
	scanf("%d",&n);
	while(n--){
		flag = 1;
		for(i=0;i<5;i++){
			scanf("%d",&exc[i]);
			if(num[2-abs(2-i)]<exc[i]||exc[i]<1) {
				flag = 0;
			}
		}
		if(!flag)
			printf("Are you kidding me? @\\/@\n");
		else
			printf("%s(%s%s%s)%s\n",arr[exc[0]-1],arr[exc[1]-1+num[0]],arr[exc[2]-1+num[0]+num[1]],arr[exc[3]-1+num[0]],arr[exc[4]-1]);
	}
	return 0;
}

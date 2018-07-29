#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

int main()
{
	char high[13][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	char low[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	char a[10],b[4];
	int n;
	int num = 0,k = 0,len = 0,i;
	scanf("%d",&n);
	getchar();
	while(n--){
		memset(a,0,sizeof(a));
		gets(a);
		if(a[0]>='0'&&a[0]<='9'){
			num = atoi(a);
			k = num/13;
			num = num%13;
			if( k!=0 && num!=0)
				printf("%s %s\n",high[k],low[num]);
			if( k!=0 && num==0)
				printf("%s\n",high[k]);
			if( k==0 && num!=0)
				printf("%s\n",low[num]);
			if( k==0 && num==0)
				printf("tret\n");
						
		}
		else{
			len = strlen(a);
			if(len == 4)
				printf("0\n");
			if(len == 3){
				for(i=1;i<13;i++){
					if(strcmp(a,low[i])==0){
						printf("%d\n",i);
						break;
					}
					if(strcmp(a,high[i])==0){
						printf("%d\n",i*13);
						break;
					}
				}
			}else if(len == 7){
				memset(b,0,sizeof(b));
				memcpy(b,a,3);
				for(i=1;i<13;i++){
					if(strcmp(b,high[i])==0){ 
						num = 13*i;
						break;
					}
				}
				for(i=0;i<3;i++)
					b[i] = a[i+4];
				for(i=1;i<13;i++){
					if(strcmp(b,low[i])==0){
						num += i;
						printf("%d\n",num);
						break;
					}
				}
			} 
			
			
		}
	
	}	
	
	return 0;
}

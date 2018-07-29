#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1001
typedef struct {
	int id;
	char s;
	int hour;
	int min;
}book;

int main()
{
	int n;
	book arr[N];
	
	scanf("%d", &n);
	while(n--) {
		int m, a, b;
		char c;
		int num = 0, res = 0;
		for(int i = 0; i<N; i++) {
			arr[i].s = 'A';
		}
		scanf("%d",&m);
		getchar();
		c = getchar();
		scanf("%d:%d",&a, &b);
		while(m!=0) {
			
			if(c == 'S') {
				arr[m].id = m;
				arr[m].s = c;
				arr[m].hour = a;
				arr[m].min = b;
			}
			if(c == 'E' && arr[m].s == 'S') {
				num++;
				if(arr[m].min < b) {
					res += b-arr[m].min+60;
					res += 60*(a-arr[m].hour-1);
				} else {
					res += b-arr[m].min;
					res += 60*(a-arr[m].hour);
				}
				arr[m].s = 'E';
			}
			scanf("%d",&m);
			getchar();
			c = getchar();
			scanf("%d:%d",&a, &b);

		}
		if(num != 0) {
			printf("%d %.0lf\n", num ,res*1.0/num);
			//printf("%d %d\n", num, (int)(res*1.0/num+0.5));
		}
			
		else
			printf("0 0\n");
		
	}
	
	return 0;
 } 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1001

int arr[N] ,res[N];
int flag = 0;
int count = 0;

void find(int a, int b, int kind) {
	int left = -1, right = -1;
	if (a>b)	return ;
	if (b-a >= 1) {
		if(kind == 0) {
			for (int i=a+1; i<=b; i++) {
				if(arr[i] < arr[a]) {
					if(left < 0) 
						left = i;
					if(right > 0 && i>right)
						flag = 1;
				}
				else {
					if(right < 0)
						right = i;
				}
			} 
		}
		else {
			for (int i=a+1; i<=b; i++) {
				if(arr[i] >= arr[a]) {
					if(left < 0) 
						left = i;
					if(right > 0 && i>right)
						flag = 1;
				}
				else {
					if(right < 0)
						right = i;
				}
			} 
			
		}
		if(left > 0) {
			if(right > 0)
				find (a+1, right-1, kind);
			else
				find (a+1, b, kind);
		}
		if(right > 0) {
			find(right, b, kind);
		}
		
	}
	res[count] = arr[a];
	count++;
}

int main() {
	int n, kind = 0;
	
	scanf("%d", &n);
	for(int i = 0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	if( n > 1 && arr[0] <= arr[1] )
		kind = 1; 
	find (0, n-1, kind);
	if (flag == 1) {
		puts("NO");
		return 0;
	}	
	puts("YES");
	for(int i=0; i<n; i++) {
		printf("%d", res[i]);
		if(i!=n-1)
			putchar(' ');
	}
		
	return 0;
}

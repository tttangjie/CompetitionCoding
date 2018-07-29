#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100001

int a[N];
/*int find(int x, int n) {
	int left = 0, right = n-1, mid;
	while(left<=right) {
		mid = (left+right)/2;
		if(x<a[mid]) 
			right = mid -1;
		else
			left = mid + 1;
	}
	return left;
}*/

int main() {
	int n, line = 0, t;
	scanf("%d%d", &n, &t);
	a[line] = t; 
	line ++;
	n --;
	while(n--) {
		scanf("%d", &t);
		if(t>a[line-1]) {
			a[line] = t;
			line++;
		} else
			//a[find(t, line)] = t;
			*upper_bound(a, a+line, t) = t;
	}
	printf("%d\n", line);
	return 0;
}

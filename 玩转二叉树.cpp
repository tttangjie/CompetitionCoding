#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;
#define N 31

typedef struct {
	int left;
	int right;
}bitree;

map<int, int> res;
int arr[N];
int brr[N];
int node = 1;

int find(int a, int b, int c, int d) {
	int t = -1;
	if ( a>b || c>d )
		return -1;
	//printf("%d ", arr[a]);
	for(int i = c; i <= d; i++) {
		if(brr[i] == arr[a]){
			t = i;
			break;
		}
	}
	if (t!=c) {
		node = 2*node+1;
		res[ node ] = find(a+1, a+t-c, c, t-1);
		node = (node-1) / 2;
	}
	if (t!=d){
		node = 2*node;
		res[ node ] = find(b-d+t+1, b, t+1, d);
		node = node/2;
	}
	return arr[a];
}

int main() {
	int n, count = 0;
	map<int, int>::iterator it;

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &brr[i]);
	}
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	res[node] = arr[0];
	find(0, n-1, 0, n-1);
	for(it = res.begin(); it!=res.end(); it++) {
		printf("%d",it->second);
		count++;
		if(count != n)
			putchar(' ');
	}
	
	return 0;
} 

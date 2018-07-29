#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#define N 100001
#define K 10000
using namespace std;
typedef struct {
	int addr;
	int key;
	int next;
}linker;
int main() {
	int start, n;
	int i, x, y, t, s;
	map<int,int> map; 
	vector<linker> b, c;
	vector<linker>::iterator it;
	linker a[N], temp;
	scanf("%d%d",&start, &n);
	for (i=0; i<n; i++) {
		scanf("%d%d%d", &x, &t, &y);
		a[x].addr = x;
		a[x].key = t;
		a[x].next = y;
	}
	s = start;
	while(s != -1) {
		if( map[ abs(a[s].key) ] == 0) {
			map[ abs(a[s].key) ] = 1;
			temp.addr = a[s].addr;
			temp.key = a[s].key;
			b.push_back(temp);
		}
		else {
			temp.addr = a[s].addr;
			temp.key = a[s].key;
			c.push_back(temp);
		}
		s = a[s].next;
	}
	for (it = b.begin(); it!=b.end(); it++) {
		if (it != b.end()-1)
			printf("%05d %d %05d\n", it->addr, it->key, (it+1)->addr);
		else 
			printf("%05d %d -1\n", it->addr, it->key);
	}
	for (it = c.begin(); it!=c.end(); it++) {
		if (it != c.end()-1)
			printf("%05d %d %05d\n", it->addr, it->key, (it+1)->addr);
		else 
			printf("%05d %d -1\n", it->addr, it->key);
	}
	
	
	return 0;
}

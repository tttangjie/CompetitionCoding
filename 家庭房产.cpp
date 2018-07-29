#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define N 10000
using namespace std;

typedef struct  {
	int no;
	int count;
	double num;
	double area;
}hstruct; 

bool compare(hstruct a, hstruct b) {
	if(a.area == b.area) 
		return a.no < b.no;
	else
		return a.area > b.area;
}

int pre[N];
int flag[N];
hstruct home[N];

int find(int x) {
	int root = x;
	while (root != pre[root]) {
		root = pre[root];
	}
	
	int p = x, t;
	while (pre[p] != root) {
		t = pre[p];
		pre[p] = root;
		p = t;
	}
	return root;
}

void join (int x, int y) {
	int fx = find(x), fy = find (y);
	if(fx != fy) {
		if(fx < fy) {
			home[fx].count += home[fy].count;
			home[fx].num += home[fy].num;
			home[fx].area += home[fy].area;
			home[fy].count = 0;
			home[fy].num = 0;
			home[fy].area = 0;
			pre [fy] = fx;
		}
			
		else {
			home[fy].count += home[fx].count;
			home[fy].num += home[fx].num;
			home[fy].area += home[fx].area;
			home[fx].count = 0;
			home[fx].num = 0;
			home[fx].area = 0;
			pre [fx] = fy;
		}
	}
}

int main() {
	int K, i, t = 0;
	int per, fa, mo, k, pernum, perarea;
	int ch[5];
	hstruct arr[N];
	for(i=0;i<N;i++) {
		pre[i] = i;
		home[i].count = 1;
		home[i].no = i;
	}
	memset(flag, 0, sizeof(flag));
	scanf("%d",&K);
	while (K--) {
		scanf("%d%d%d",&per, &fa, &mo);
		scanf("%d", &k);
		if(k != 0)
			for (i=0; i<k; i++) 
				scanf("%d", &ch[i]);
		scanf("%d%d", &pernum, &perarea);
		home[find(per)].num += pernum;
		home[find(per)].area += perarea;
		flag [per] = 1;
		if(fa != -1) {
			flag [fa] = 1;
			join(per, fa);
		}
		if(mo != -1) {
			flag [mo] = 1;
			join(per, mo);
		}
		if (k != 0)
			for(i=0; i<k; i++) {
				flag[ch[i]] = 1;
				join(per, ch[i]);
			}
	}
	for (i=0; i<N; i++) {
		if(flag[i] && find(i) == i) {
			home[i].num = home[i].num/home[i].count;
			home[i].area = home[i].area/home[i].count;
			arr[t] = home[i];
			t++;
		}
	}
	sort(arr, arr+t, compare);
	printf("%d\n",t);
	for (i=0; i<t; i++) {
		printf("%04d %d %.3lf %.3lf\n",arr[i].no, arr[i].count, arr[i].num, arr[i].area);
	}

	return 0;
} 

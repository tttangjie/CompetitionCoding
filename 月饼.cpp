#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define N 1005
using namespace std;

typedef struct {
	double num;
	double money;
	double average;
}type;

bool compare(type a, type b) {
	return a.average > b.average;
}

int main() {
	int n, m, t = 0;
	type moon[N];
	double res = 0;
	scanf("%d%d",&n, &m);
	for (int i = 0; i<n; i++) 
		scanf("%lf", &moon[i].num);
	for (int i = 0; i<n; i++) {
		scanf("%lf", &moon[i].money);
		moon[i].average = moon[i].money*1.0 / moon[i].num;
	}
	sort(moon, moon+n, compare);
	/*while(m - moon[t].num >= 0) {
		res += moon[t].money;
		m -= moon[t].num;
		t++;
 	}
 	res += m*moon[t].average;*/
	
	for(int i=0; i<n; i++) {
		if(moon[i].num < m) {
			res += moon[i].money;
			m -= moon[i].num;
		} else {
			res += moon[i].average * m;
			break;
		}
	}
 	printf("%.2lf\n", res);
	return 0;
}

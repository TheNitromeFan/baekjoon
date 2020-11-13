#include <cstdio>

int main(){
	int w, h;
	scanf("%d %d", &w, &h);
	int p, q;
	scanf("%d %d", &p, &q);
	int t;
	scanf("%d", &t);
	p += t;
	q += t;
	p %= (2 * w);
	q %= (2 * h);
	if(p > w){
		p = 2 * w - p;
	}
	if(q > h){
		q = 2 * h - q;
	}
	printf("%d %d", p, q);
	return 0;
}

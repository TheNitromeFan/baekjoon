#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int x, y, z, r, a, b, c, d;
		scanf("%d %d %d %d %d %d %d %d", &x, &y, &z, &r, &a, &b, &c, &d);
		printf("%.9lf\n", PI * r * r);
	}
	return 0;
}

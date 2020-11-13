#include <cstdio>

int main(){
	int test = 0;
	while(true){
		int n;
		scanf("%d", &n);
		if(n < 0){
			break;
		}
		++test;
		long long mx = 0, my = 0, m = 0;
		for(int i = 0; i < n; ++i){
			int xi, yi, mi;
			scanf("%d %d %d", &xi, &yi, &mi);
			mx += mi * xi;
			my += mi * yi;
			m += mi;
		}
		printf("Case %d: %.2f %.2f\n", test, mx / (double)m, my / (double)m);
	}
	return 0;
}

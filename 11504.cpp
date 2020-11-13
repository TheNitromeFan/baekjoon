#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		long long x = 0;
		for(int i = 0; i < m; ++i){
			x *= 10;
			int d;
			scanf("%d", &d);
			x += d;
		}
		long long y = 0;
		for(int i = 0; i < m; ++i){
			y *= 10;
			int d;
			scanf("%d", &d);
			y += d;
		}
		int wheel[100] = {};
		for(int j = 0; j < n; ++j){
			scanf("%d", &wheel[j]);
		}
		int cnt = 0;
		for(int j = 0; j < n; ++j){
			long long z = 0;
			for(int k = 0; k < m; ++k){
				z *= 10;
				z += wheel[(j + k) % n];
			}
			if(z >= x && z <= y){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

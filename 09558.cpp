#include <cstdio>
#include <cstdlib>

int main(){
	int t;
	scanf("%d", &t);
	for(int t0 = 0; t0 < t; ++t0){
		int a[1000] = {}, b[1000] = {};
		int n, m;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		int min = 2000000;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j){
			scanf("%d", &b[j]);
			for(int i = 0; i < n; ++i){
				int cmp = abs(a[i] - b[j]);
				if(cmp < min){
					min = cmp;
				}
			}
		}
		printf("%d\n", min);
	}
	return 0;
}

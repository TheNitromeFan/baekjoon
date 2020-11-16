#include <cstdio>

int main(){
	int z;
	scanf("%d", &z);
	for(int a0 = 0; a0 < z; ++a0){
		static int x[1000001] = {};
		int n, k;
		scanf("%d %d", &n, &k);
		if(n == 1){
			printf("%d\n", k);
			continue;
		}
		int q = k / (2 * n - 2), r = k % (2 * n - 2);
		x[1] = q;
		x[n] = q;
		for(int i = 2; i < n; ++i){
			x[i] = 2 * q;
		}
		if(r < n){
			for(int i = 1; i <= r; ++i){
				++x[i];
			}
		}else{
			for(int i = 1; i < n; ++i){
				++x[i];
			}
			for(int i = n, j = n; j <= r; --i, ++j){
				++x[i];
			}
		}
		for(int i = 1; i <= n; ++i){
			printf("%d ", x[i]);
		}
		printf("\n");
	}
	return 0;
}

#include <cstdio>

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	int h[501] = {}, psum[501] = {};
	for(int i = 1; i <= n; ++i){
		scanf("%d", &h[i]);
		psum[i] = psum[i - 1] + h[i];
	}
	for(int j = 0; j < q; ++j){
		int sj, ej;
		scanf("%d %d", &sj, &ej);
		printf("%d\n", psum[ej] - psum[sj - 1]);
	}
	return 0;
}

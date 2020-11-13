#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int w[101], v[101];
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &w[i], &v[i]);
	}
	static int b[101][100001] = {}; // b[i][j]: up to i-th item, max weight j
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= k; ++j){
			b[i][j] = b[i-1][j];
			if(j >= w[i]){
				int tmp = b[i-1][j-w[i]] + v[i];
				if(tmp > b[i][j]){
					b[i][j] = tmp;
				}
			}
		}
	}
	printf("%d", b[n][k]);
	return 0;
}

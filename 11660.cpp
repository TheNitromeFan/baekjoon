#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int a[1025][1025], psum[1025][1025] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &a[i][j]);
			psum[i][j] = a[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
		}
	}
	for(int k = 0; k < m; ++k){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1]);
	}
	return 0;
}

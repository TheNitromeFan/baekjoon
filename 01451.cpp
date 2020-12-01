#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[100][100];
	for(int i = 0; i < n; ++i){
		char s[101];
		scanf("%s", s);
		for(int j = 0; j < m; ++j){
			a[i][j] = s[j] - '0';
		}
	}
	long long psum[100][100] = {};
	psum[0][0] = a[0][0];
	for(int j = 1; j < m; ++j){
		psum[0][j] = psum[0][j - 1] + a[0][j];
	}
	for(int i = 1; i < n; ++i){
		psum[i][0] = psum[i - 1][0] + a[i][0];
	}
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < m; ++j){
			psum[i][j] = psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1] + a[i][j];
		}
	}
	long long ans = 0;
	for(int i = 0; i < n - 1; ++i){
		for(int j = 0; j < m - 1; ++j){
			ans = max(ans, psum[i][j] * (psum[n - 1][j] - psum[i][j]) * (psum[n - 1][m - 1] - psum[n - 1][j]));
			ans = max(ans, psum[i][j] * (psum[i][m - 1] - psum[i][j]) * (psum[n - 1][m - 1] - psum[i][m - 1]));
			ans = max(ans, psum[n - 1][j] * (psum[i][m - 1] - psum[i][j]) * (psum[n - 1][m - 1] - psum[n - 1][j] - psum[i][m - 1] + psum[i][j]));
			ans = max(ans, psum[i][m - 1] * (psum[n - 1][j] - psum[i][j]) * (psum[n - 1][m - 1] - psum[n - 1][j] - psum[i][m - 1] + psum[i][j]));
		}
	}
	for(int i1 = 1; i1 < n - 1; ++i1){
		for(int i2 = 0; i2 < i1; ++i2){
			ans = max(ans, psum[i2][m - 1] * (psum[i1][m - 1] - psum[i2][m - 1]) * (psum[n - 1][m - 1] - psum[i1][m - 1]));
		}
	}
	for(int j1 = 1; j1 < m - 1; ++j1){
		for(int j2 = 0; j2 < j1; ++j2){
			ans = max(ans, psum[n - 1][j2] * (psum[n - 1][j1] - psum[n - 1][j2]) * (psum[n - 1][m - 1] - psum[n - 1][j1]));
		}
	}
	printf("%lld", ans);
	return 0;
}

#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		static long long c[200001], b[200001];
		long long c_sum = 0, b_sum = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%lld", &c[i]);
			c_sum += c[i];
		}
		for(int j = 1; j <= m; ++j){
			scanf("%lld", &b[j]);
			b_sum += b[j];
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			if(c[i] * n < c_sum && c[i] * m > b_sum){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

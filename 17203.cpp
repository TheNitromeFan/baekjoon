#include <cstdio>
#include <cstdlib>
#define MAX (1000 + 1)

int main(){
	int a[MAX], d[MAX], dp[MAX] = {};
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < n; ++i){
		d[i] = abs(a[i + 1] - a[i]);
		dp[i] = dp[i - 1] + d[i];
	}
	for(int j = 0; j < m; ++j){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[e - 1] - dp[s - 1]);
	}
	return 0;
}

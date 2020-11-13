#include <cstdio>
#include <algorithm>
#include <limits>
#define MAX 200000

using namespace std;

int main(){
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	int a[MAX], dp[MAX] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i * m + j]);
		}
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int p = i * m + j;
			dp[p] = numeric_limits<int>::min();
			for(int jump = 1; jump <= min(d, i); ++jump){
				int x = i - jump;
				for(int y = max(0, j - (d - jump)); y <= min(m - 1, j + (d - jump)); ++y){
					int tmp = x * m + y;
					if(dp[p] < dp[tmp] + a[tmp] * a[p]){
						dp[p] = dp[tmp] + a[tmp] * a[p];
					}
				}
			}
		}
	}
	int ans = numeric_limits<int>::min();
	for(int j = 0; j < m; ++j){
		if(ans < dp[(n - 1) * m + j]){
			ans = dp[(n - 1) * m + j];
		}
	}
	printf("%d", ans);
	return 0;
}

#include <cstdio>
#include <cstring>
#define MAX (300 + 1)

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int points[MAX][MAX] = {};
	for(int i = 0; i < k; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if(points[u][v] < w){
			points[u][v] = w;
		}
	}
	int dp[MAX][MAX] = {}; // dp[i][j]: city i, visited j
	memset(dp, -1, sizeof(dp));
	dp[1][1] = 0;
	for(int u = 1; u < n; ++u){
		for(int v = 1; v < m; ++v){
			for(int x = u + 1; x <= n; ++x){
				if(points[u][x] > 0 && dp[u][v] != -1 && dp[x][v + 1] < dp[u][v] + points[u][x]){
					dp[x][v + 1] = dp[u][v] + points[u][x];
				}
			}
		}
	}
	/*
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= m; ++v){
			printf("%d ", dp[u][v]);
		}
		printf("\n");
	}
	*/
	int ans = -1;
	for(int v = 1; v <= m; ++v){
		if(ans < dp[n][v]){
			ans = dp[n][v];
		}
	}
	printf("%d", ans);
	return 0;
}

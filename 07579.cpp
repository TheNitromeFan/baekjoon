#include <cstdio>
#include <cstring>
#define MAX_APPS 100
#define MAX_COST (10000 + 1)

int dp[MAX_APPS][MAX_COST];

int max_memory(int memory[MAX_APPS], int cost[MAX_APPS], int n, int idx, int total_cost){
	if(idx >= n){
		return 0;
	}
	if(dp[idx][total_cost] != -1){
		return dp[idx][total_cost];
	}
	dp[idx][total_cost] = max_memory(memory, cost, n, idx + 1, total_cost);
	if(cost[idx] <= total_cost){
		int cmp = memory[idx] + max_memory(memory, cost, n, idx + 1, total_cost - cost[idx]);
		if(dp[idx][total_cost] < cmp){
			dp[idx][total_cost] = cmp;
		}
	}
	return dp[idx][total_cost];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int memory[MAX_APPS], cost[MAX_APPS];
	for(int i = 0; i < n; ++i){
		scanf("%d", &memory[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &cost[i]);
	}
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	while(true){
		if(max_memory(memory, cost, n, 0, ans) >= m){
			break;
		}
		++ans;
	}
	printf("%d", ans);
	return 0;
}

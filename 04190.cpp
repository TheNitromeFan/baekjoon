#include <cstdio>
#include <cstring>

void solve(){
	int price;
	scanf("%d", &price);
	int n;
	scanf("%d", &n);
	int bills[100000] = {};
	for(int i = 1; i <= n; ++i){
		scanf("%d", &bills[i]);
	}
	unsigned dp[100000];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = price - 1; j >= 0; --j){
			if(dp[j] == -1){
				continue;
			}
			if(dp[j + bills[i]] > dp[j] + 1){
				dp[j + bills[i]] = dp[j] + 1;
			}
		}
	}
	int p = price;
	while(true){
		if(dp[p] != -1){
			printf("%d %d\n", p, dp[p]);
			return;
		}
		++p;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		solve();
	}
	return 0;
}

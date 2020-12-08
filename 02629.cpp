#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAXN (30 + 1)
#define MAXW (30 * 500 + 1)

using namespace std;

void weigh(bool dp[MAXN][MAXW], int weights[MAXN], int n, int w, int sum){
	if(w > n){
		return;
	}
	if(dp[w][sum]){
		return;
	}
	dp[w][sum] = true;
	weigh(dp, weights, n, w + 1, sum);
	weigh(dp, weights, n, w + 1, sum + weights[w]);
	weigh(dp, weights, n, w + 1, abs(sum - weights[w]));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int weights[MAXN];
	for(int i = 0; i < n; ++i){
		cin >> weights[i];
	}
	bool dp[MAXN][MAXW] = {};
	weigh(dp, weights, n, 0, 0);
	int m;
	cin >> m;
	for(int j = 0; j < m; ++j){
		int marble;
		cin >> marble;
		cout << (marble <= MAXW && dp[n][marble] ? 'Y' : 'N') << ' ';
	}
	return 0;
}

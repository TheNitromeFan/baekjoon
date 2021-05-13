#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	vector<vector<pair<int, int>>> adj(d + 1);
	for(int i = 0; i < n; ++i){
		int s, e, dist;
		cin >> s >> e >> dist;
		if(e <= d){
			adj[e].push_back(make_pair(s, dist));
		}
	}
	vector<int> dp(d + 1);
	for(int x = 1; x <= d; ++x){
		dp[x] = dp[x - 1] + 1;
		for(pair<int, int> p : adj[x]){
			int y = p.first, dist = p.second;
			dp[x] = min(dp[x], dp[y] + dist);
		}
	}
	cout << dp[d];
	return 0;
}

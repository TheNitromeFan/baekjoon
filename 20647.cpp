#include <iostream>
#include <vector>

using namespace std;

void sum_dist(vector<vector<int>> &adj, int cur, int prev, int &ans){
	int cnt = 0;
	for(int next : adj[cur]){
		if(next != prev){
			++cnt;
			sum_dist(adj, next, cur, ans);
		}
	}
	ans += cnt;
	while(cnt > 0){
		++ans;
		cnt /= 2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	sum_dist(adj, 1, -1, ans);
	cout << ans;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> like(n + 1);
	vector<bool> memo(n + 1);
	for(int j = 0; j < q; ++j){
		int u;
		cin >> u;
		if(memo[u]){
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		if(!like[u]){
			like[u] = true;
			++ans;
		}
		for(int v : adj[u]){
			if(!like[v]){
				like[v] = true;
				++ans;
			}
		}
		cout << ans << '\n';
		memo[u] = true;
	}
	return 0;
}

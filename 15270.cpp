#include <iostream>
#include <vector>

using namespace std;

int vertices(vector<vector<int>> &adj, vector<bool> &used, int n, int u){
	if(u > n){
		return 0;
	}
	if(used[u]){
		return vertices(adj, used, n, u + 1);
	}
	int ret = vertices(adj, used, n, u + 1);
	used[u] = true;
	for(int v : adj[u]){
		if(!used[v]){
			used[v] = true;
			int cmp = vertices(adj, used, n, u + 1) + 2;
			if(cmp > ret){
				ret = cmp;
			}
			used[v] = false;
		}
	}
	used[u] = false;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> used(n + 1);
	int ans = vertices(adj, used, n, 1);
	if(ans < n){
		++ans;
	}
	cout << ans;
	return 0;
}

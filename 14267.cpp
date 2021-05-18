#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &g, vector<int> &c, int u, int w){
	// cout << u << ' ' << w << '\n';
	c[u] += w;
	for(int v : adj[u]){
		dfs(adj, g, c, v, w + g[v]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	int ceo = -1;
	for(int v = 1; v <= n; ++v){
		int u;
		cin >> u;
		if(u != -1){
			adj[u].push_back(v);
		}else{
			ceo = v;
		}
	}
	vector<int> give(n + 1);
	for(int i = 0; i < m; ++i){
		int v, w;
		cin >> v >> w;
		give[v] += w;
	}
	vector<int> compliments(n + 1);
	dfs(adj, give, compliments, ceo, 0);
	for(int v = 1; v <= n; ++v){
		cout << compliments[v] << ' ';
	}
	return 0;
}

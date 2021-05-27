#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

int cache[MAX][2];

void dfs(vector<vector<int>> &adj, vector<vector<int>> &tree, vector<bool> &visited, int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(visited[v]){
			continue;
		}
		tree[u].push_back(v);
		dfs(adj, tree, visited, v);
	}
}

int dp(vector<vector<int>> &tree, vector<int> &w, int u, int included){
	if(cache[u][included] != -1){
		return cache[u][included];
	}
	if(included){
		cache[u][included] = w[u];
		for(int v : tree[u]){
			cache[u][included] += dp(tree, w, v, 0);
		}
	}else{
		cache[u][included] = 0;
		for(int v : tree[u]){
			int cmp1 = dp(tree, w, v, 0);
			int cmp2 = dp(tree, w, v, 1);
			cache[u][included] += max(cmp1, cmp2);
		}
	}
	return cache[u][included];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> w(n + 1);
	for(int u = 1; u <= n; ++u){
		cin >> w[u];
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<int>> tree(n + 1);
	vector<bool> visited(n + 1);
	dfs(adj, tree, visited, 1);
	memset(cache, -1, sizeof(cache));
	int ans1 = dp(tree, w, 1, 0);
	int ans2 = dp(tree, w, 1, 1);
	cout << max(ans1, ans2) << '\n';
	return 0;
}

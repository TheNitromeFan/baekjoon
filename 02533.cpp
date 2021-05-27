#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

void dfs(vector<vector<int>> &adj, vector<vector<int>> &tree, vector<bool> &visited, int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			tree[u].push_back(v);
			dfs(adj, tree, visited, v);
		}
	}
}

int early_adaptor(vector<vector<int>> &tree, int dp[][2], int u, int early){
	if(dp[u][early] != -1){
		return dp[u][early];
	}
	if(early){
		dp[u][early] = 1;
		for(int v : tree[u]){
			dp[u][early] += min(early_adaptor(tree, dp, v, 0), early_adaptor(tree, dp, v, 1));
		}
	}else{
		dp[u][early] = 0;
		for(int v : tree[u]){
			dp[u][early] += early_adaptor(tree, dp, v, 1);
		}
	}
	return dp[u][early];
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
	vector<vector<int>> tree(n + 1);
	vector<bool> visited(n + 1);
	dfs(adj, tree, visited, 1);
	int dp[MAX][2];
	memset(dp, -1, sizeof(dp));
	cout << min(early_adaptor(tree, dp, 1, 0), early_adaptor(tree, dp, 1, 1));
	return 0;
}

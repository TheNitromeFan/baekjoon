#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &fruit, vector<bool> &visited, int node, int cost, int &ans_node, int &eccentricity){
	if(visited[node]){
		return;
	}
	visited[node] = true;
	cost += fruit[node];
	for(int next : adj[node]){
		dfs(adj, fruit, visited, next, cost, ans_node, eccentricity);
	}
	if(cost > eccentricity || (cost == eccentricity && node < ans_node)){
		ans_node = node;
		eccentricity = cost;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> fruit(n + 1);
	for(int u = 1; u <= n; ++u){
		cin >> fruit[u];
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n + 1);
	int ans_node = 1, eccentricity = 0;
	dfs(adj, fruit, visited, 1, 0, ans_node, eccentricity);
	fill(visited.begin(), visited.end(), false);
	int u = ans_node;
	eccentricity = 0;
	dfs(adj, fruit, visited, u, eccentricity, ans_node, eccentricity);
	cout << eccentricity << ' ' << min(u, ans_node);
	return 0;
}

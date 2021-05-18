#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_depth(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &depths, int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(visited[v]){
			continue;
		}
		int cmp = get_depth(adj, visited, depths, v);
		depths[u] = max(depths[u], cmp);
	}
	return depths[u] + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s, d;
	cin >> n >> s >> d;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n + 1);
	vector<int> depths(n + 1);
	get_depth(adj, visited, depths, s);
	int travel = 0;
	for(int v = 1; v <= n; ++v){
		if(v != s && depths[v] >= d){
			travel += 2;
		}
	}
	cout << travel;
	return 0;
}

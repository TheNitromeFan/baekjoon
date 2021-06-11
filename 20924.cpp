#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dfs(vector<vector<pair<int, int>>> &adj, vector<bool> &visited, int u){
	visited[u] = true;
	int ret = 0;
	for(pair<int, int> p : adj[u]){
		int v = p.first, w = p.second;
		if(!visited[v]){
			ret = max(ret, w + dfs(adj, visited, v));
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r;
	cin >> n >> r;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	vector<bool> visited(n + 1);
	int stem = 0;
	if(adj[r].size() == 1){
		visited[r] = true;
		stem += adj[r][0].second;
		int prev = r;
		r = adj[r][0].first;
		while(adj[r].size() == 2){
			visited[r] = true;
			if(adj[r][0].first == prev){
				stem += adj[r][1].second;
				prev = r;
				r = adj[r][1].first;
			}else{
				stem += adj[r][0].second;
				prev = r;
				r = adj[r][0].first;
			}
		}
	}
	int longest_branch = dfs(adj, visited, r);
	cout << stem << ' ' << longest_branch;
	return 0;
}

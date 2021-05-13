#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int paths(vector<vector<int>> &adj, vector<bool> &visited, unordered_set<int> &dest, int cur, int steps){
	if(steps == 3){
		return dest.find(cur) != dest.end();
	}
	int ret = 0;
	visited[cur] = true;
	for(int v : adj[cur]){
		if(visited[v]){
			continue;
		}
		ret += paths(adj, visited, dest, v, steps + 1);
	}
	visited[cur] = false;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	unordered_set<int> dest;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(u == 1){
			dest.insert(v);
		}
		if(v == 1){
			dest.insert(u);
		}
	}
	vector<bool> visited(n + 1);
	cout << paths(adj, visited, dest, 1, 0);
	return 0;
}

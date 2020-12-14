#include <iostream>
#include <vector>

using namespace std;

long long sum_of_depths(vector<vector<int>> &adj, vector<bool> &visited, int v, int depth){
	visited[v] = true;
	if(adj[v].size() == 1 && visited[adj[v][0]]){
		return depth;
	}
	long long ret = 0;
	for(int x : adj[v]){
		if(!visited[x]){
			ret += sum_of_depths(adj, visited, x, depth + 1);
		}
	}
	return ret;
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
	vector<bool> visited(n + 1);
	cout << (sum_of_depths(adj, visited, 1, 0) % 2 ? "Yes" : "No");
	return 0;
}

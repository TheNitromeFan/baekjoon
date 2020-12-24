#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int total_owed(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &amt, int n, int start){
	queue<int> q;
	int owed = 0;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		owed += amt[u];
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return owed;
}

bool even(vector<vector<int>> &adj, vector<int> &owed, int n){
	vector<bool> visited(n);
	for(int u = 0; u < n; ++u){
		if(!visited[u]){
			int o = total_owed(adj, visited, owed, n, u);
			if(o != 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> owed(n);
	for(int i = 0; i < n; ++i){
		cin >> owed[i];
	}
	vector<vector<int>> adj(n);
	for(int j = 0; j < m; ++j){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << (even(adj, owed, n) ? "POSSIBLE" : "IMPOSSIBLE");
	return 0;
}

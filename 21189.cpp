#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &adj, int n){
	queue<int> q;
	vector<int> dist(n + 1, -1);
	q.push(1);
	dist[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == n){
			break;
		}
		for(int v : adj[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
	return dist[n];
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
	cout << bfs(adj, n) - 1 << '\n';
	return 0;
}

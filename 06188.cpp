#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void traverse(vector<vector<int>> &adj, vector<int> &dist){
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < c; ++i){
		int e, b1, b2;
		cin >> e >> b1 >> b2;
		adj[e].push_back(b1);
		adj[e].push_back(b2);
		adj[b1].push_back(e);
		adj[b2].push_back(e);
	}
	vector<int> dist(n + 1, -1);
	traverse(adj, dist);
	for(int u = 1; u <= n; ++u){
		cout << dist[u] << '\n';
	}
	return 0;
}

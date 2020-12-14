#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int replace(vector<vector<int>> &adj, int n, int start, int end){
	queue<int> q;
	vector<int> visited(n + 1, -1);
	q.push(start);
	visited[start] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == end){
			return visited[end];
		}
		for(int v : adj[u]){
			if(visited[v] == -1){
				q.push(v);
				visited[v] = visited[u] + 1;
			}
		}
	}
	return visited[end];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << replace(adj, n, a, b);
	return 0;
}

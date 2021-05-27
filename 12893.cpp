#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &adj, vector<int> &visited, int x){
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(visited[v] == visited[u]){
				return false;
			}else if(visited[v] == 0){
				q.push(v);
				visited[v] = 3 - visited[u];
			}
		}
	}
	return true;
}

bool bipartite(vector<vector<int>> &adj, int n){
	vector<int> visited(n + 1);
	for(int u = 1; u <= n; ++u){
		if(visited[u] == 0){
			bool tmp = bfs(adj, visited, u);
			if(!tmp){
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
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << bipartite(adj, n);
	return 0;
}

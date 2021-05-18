#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 1000000000

using namespace std;

int bfs(vector<vector<pair<int, int>>> &adj, int n, int start, int end){
	vector<int> dist(n + 1, MAX);
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == end){
			return dist[u];
		}
		for(pair<int, int> p : adj[u]){
			int v = p.first, w = p.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				q.push(v);
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	for(int j = 0; j < m; ++j){
		int u, v;
		cin >> u >> v;
		cout << bfs(adj, n, u, v) << '\n';
	}
	return 0;
}

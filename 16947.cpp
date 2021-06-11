#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_cycle(vector<vector<int>> &adj, vector<bool> &visited, int start, int cur, int cnt){
	if(cur == start && cnt >= 2){
		return true;
	}
	visited[cur] = true;
	for(int next : adj[cur]){
		if(!visited[next] && is_cycle(adj, visited, start, next, cnt + 1)){
			return true;
		}else if(next == start && cnt >= 2){
			return true;
		}
	}
	return false;
}

int dist_to_cycle(vector<vector<int>> &adj, vector<bool> &cycle, int n, int start){
	vector<int> dist(n + 1, -1);
	queue<int> q;
	vector<bool> visited(n + 1);
	dist[start] = 0;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(cycle[u]){
			return dist[u];
		}
		for(int v : adj[u]){
			if(!visited[v]){
				dist[v] = dist[u] + 1;
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> cycle(n + 1);
	for(int u = 1; u <= n; ++u){
		vector<bool> visited(n + 1);
		cycle[u] = is_cycle(adj, visited, u, u, 0);
		// cout << cycle[u] << '\n';
	}
	for(int u = 1; u <= n; ++u){
		cout << dist_to_cycle(adj, cycle, n, u) << ' ';
	}
	return 0;
}

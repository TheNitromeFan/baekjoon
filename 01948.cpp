#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void longest_path(vector<vector<pair<int, int>>> &adj, vector<int> &degree, vector<int> &dist, int n, int start){
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(pair<int, int> p : adj[u]){
			int v = p.first, w = p.second;
			if(dist[v] < dist[u] + w){
				dist[v] = dist[u] + w;
			}
			--degree[v];
			if(degree[v] == 0){
				q.push(v);
			}
		}
	}
}

int roads(vector<vector<pair<int, int>>> &rev, vector<int> &dist, int n, int end){
	vector<bool> visited(n + 1);
	queue<int> q;
	visited[end] = true;
	q.push(end);
	int ret = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(pair<int, int> p : rev[u]){
			int v = p.first, w = p.second;
			if(dist[u] - dist[v] == w){
				++ret;
				if(!visited[v]){
					visited[v] = true;
					q.push(v);
				}
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1), rev(n + 1);
	vector<int> degree(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		rev[v].push_back(make_pair(u, w));
		++degree[v];
	}
	int start, end;
	cin >> start >> end;
	vector<int> dist(n + 1);
	longest_path(adj, degree, dist, n, start);
	cout << dist[end] << '\n' << roads(rev, dist, n, end);
	return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#define MAX 1001

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

int dijkstra(vector<vector<pair<int, int>>> &adj, int forbidden[][MAX][2], int n, int a, int b, int k){
	int dist[MAX];
	memset(dist, -1, sizeof(dist));
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	bool visited[MAX] = {};
	dist[a] = k;
	pq.push(make_pair(a, k));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == b){
			return dist[b];
		}
		if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, int> q : adj[u]){
			int v = q.first, w = q.second;
			int ndist = dist[u] + w;
			if(forbidden[u][v][0] != -1 && forbidden[u][v][1] != -1 && dist[u] >= forbidden[u][v][0] && dist[u] < forbidden[u][v][1]){
				ndist = forbidden[u][v][1] + w;
			}
			if(dist[v] == -1 || dist[v] > ndist){
				dist[v] = ndist;
				pq.push(make_pair(v, dist[v]));
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
	int a, b, k, g;
	cin >> a >> b >> k >> g;
	vector<int> george_path(g);
	for(int i = 0; i < g; ++i){
		cin >> george_path[i];
	}
	vector<vector<pair<int, int>>> adj(n + 1);
	int adj_mat[MAX][MAX];
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj_mat[u][v] = w;
		adj[v].push_back(make_pair(u, w));
		adj_mat[v][u] = w;
	}
	int forbidden[MAX][MAX][2];
	memset(forbidden, -1, sizeof(forbidden));
	int time = 0;
	for(int i = 0; i + 1 < g; ++i){
		int u = george_path[i], v = george_path[i + 1];
		int w = adj_mat[u][v];
		forbidden[u][v][0] = time;
		forbidden[v][u][0] = time;
		time += w;
		forbidden[u][v][1] = time;
		forbidden[v][u][1] = time;
	}
	cout << dijkstra(adj, forbidden, n, a, b, k) - k;
	return 0;
}

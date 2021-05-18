#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 1000000000

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

int dijkstra(vector<vector<pair<int, int>>> &adj, int n, int s, int t){
	vector<int> dist(n + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(n + 1);
	dist[s] = 0;
	pq.push(make_pair(s, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == t){
			return dist[t];
		}
		if(visited[u]){
			continue;
		}
		for(pair<int, int> q : adj[u]){
			int v = q.first, w = q.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
		visited[u] = true;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	int s, t;
	cin >> s >> t;
	cout << dijkstra(adj, n, s, t);
	return 0;
}

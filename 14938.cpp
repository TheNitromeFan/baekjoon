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

int dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &items, int start, int n, int m){
	vector<int> dist(n + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(n + 1);
	dist[start] = 0;
	pq.push(make_pair(start, 0));
	int ret = 0;
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(visited[u]){
			continue;
		}
		if(dist[u] > m){
			break;
		}
		ret += items[u];
		visited[u] = true;
		for(pair<int, int> q : adj[u]){
			int v = q.first, w = q.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> items(n + 1);
	for(int u = 1; u <= n; ++u){
		cin >> items[u];
	}
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int a0 = 0; a0 < r; ++a0){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	int max_items = 0;
	for(int u = 1; u <= n; ++u){
		int cmp = dijkstra(adj, items, u, n, m);
		if(max_items < cmp){
			max_items = cmp;
		}
	}
	cout << max_items;
	return 0;
}

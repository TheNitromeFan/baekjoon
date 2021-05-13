#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, long long> a, pair<int, long long> b){
			return a.second > b.second;
		}
};

long long dijkstra(vector<vector<pair<int, long long>>> &adj, int n){
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, Cmp> pq;
	vector<long long> dist(n, -1);
	vector<bool> visited(n);
	dist[0] = 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		pair<int, long long> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == n - 1){
			return p.second;
		}
		if(visited[u]){
			continue;
		}
		for(pair<int, long long> q : adj[u]){
			int v = q.first;
			long long d = q.second;
			if(dist[v] == -1 || dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
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
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	a[n - 1] = 0;
	vector<vector<pair<int, long long>>> adj(n);
	for(int j = 0; j < m; ++j){
		int u, v;
		long long t;
		cin >> u >> v >> t;
		if(!a[u] && !a[v]){
			adj[u].push_back(make_pair(v, t));
			adj[v].push_back(make_pair(u, t));
		}
	}
	cout << dijkstra(adj, n);
	return 0;
}

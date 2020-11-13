#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>> adj, int n){
	printf("%d\n", n - 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n + 1, numeric_limits<int>::max());
	vector<bool> visited(n + 1, false);
	vector<int> prev(n + 1, 0);
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	while(!pq.empty()){
		// printf("%d %d\n", pq.top().first, pq.top().second);
		int u = pq.top().second;
		pq.pop();
		if(visited[u]){
			continue;
		}
		if(u != 1){
			printf("%d %d\n", prev[u], u);
		}
		for(auto tmp : adj[u]){
			int v = tmp.first, w = tmp.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				prev[v] = u;
				pq.push(make_pair(dist[v], v));
			}
		}
		visited[u] = true;
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	dijkstra(adj, n);
	return 0;
}

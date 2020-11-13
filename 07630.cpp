#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adj, int size, int src, int dest){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> dist(size, numeric_limits<int>::max());
	dist[src] = 0;
	q.push(make_pair(0, src));
	while(!q.empty()){
		pair<int, int> p0 = q.top();
		q.pop();
		int d = p0.first;
		int u = p0.second;
		for(pair<int, int> p : adj[u]){
			int w = p.first;
			int v = p.second;
			if(d + w < dist[v]){
				dist[v] = d + w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	printf("%d\n", dist[dest]);
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		vector<vector<pair<int, int>>> adj;
		adj.resize(n);
		for(int i = 0; i < n; ++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(w, v));
			adj[v].push_back(make_pair(w, u));
		}
		int q;
		scanf("%d", &q);
		for(int q0 = 0; q0 < q; ++q0){
			int src, dest;
			scanf("%d %d", &src, &dest);
			dijkstra(adj, n, src, dest);
		}
	}
	return 0;
}

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Cmp{
	public:
		bool operator() (pair<int, int> a, pair<int, int> b){
			return a.second < b.second;
		}
};

int dijkstra(vector<vector<pair<int, int>>> &adj, int start, int end){
	vector<int> dist(adj.size(), -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	dist[start] = 0;
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, int> tmp = pq.top();
		pq.pop();
		int u = tmp.first;
		for(pair<int, int> tmp : adj[u]){
			int v = tmp.first, d = tmp.second;
			if(dist[v] == -1 || dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
	return dist[end];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int>>> adj;
	adj.resize(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v, e;
		scanf("%d %d %d", &u, &v, &e);
		adj[u].push_back(make_pair(v, e));
		adj[v].push_back(make_pair(u, e));
	}
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = -1;
	int x = dijkstra(adj, 1, a), y = dijkstra(adj, a, b), z = dijkstra(adj, b, n);
	if(x != -1 && y != -1 && z != -1 && (ans == -1 || ans > x + y + z)){
		ans = x + y + z;
	}
	x = dijkstra(adj, 1, b), y = dijkstra(adj, b, a), z = dijkstra(adj, a, n);
	if(x != -1 && y != -1 && z != -1 && (ans == -1 || ans > x + y + z)){
		ans = x + y + z;
	}
	printf("%d", ans);
	return 0;
}

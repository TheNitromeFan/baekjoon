#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

class Compare{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

void dijkstra(vector<pair<int, int>> adj[501], vector<pair<int, int>> trace[501],
			int dist[501], int src){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push(make_pair(src, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first, w = p.second;
		if(w > dist[u]){
			continue;
		}
		for(pair<int, int> &a : adj[u]){
			int v = a.first, d = a.second;
			if(d == -1){
				continue;
			}
			if(dist[v] > d + w){
				dist[v] = d + w;
				pq.push(make_pair(v, dist[v]));
				trace[v].clear();
				trace[v].push_back(make_pair(u, dist[v]));
			}else if(dist[v] == d + w){
				trace[v].push_back(make_pair(u, dist[v]));
			}
		}
	}
}

void erase_paths(vector<pair<int, int>> adj[501], vector<pair<int, int>> trace[501], int dest){
	queue<int> q;
	q.push(dest);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(pair<int, int> p : trace[v]){
			int u = p.first;
			for(pair<int, int> &edge : adj[u]){
				if(edge.first == v){
					edge.second = -1;
				}
			}
			q.push(u);
		}
	}
}

int main(){
	while(true){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		int src, dest;
		scanf("%d %d", &src, &dest);
		vector<pair<int, int>> adj[501];
		for(int a0 = 0; a0 < m; ++a0){
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			adj[u].push_back(make_pair(v, p));
		}
		int dist[501];
		for(int i = 0; i < n; ++i){
			dist[i] = numeric_limits<int>::max();
		}
		dist[src] = 0;
		vector<pair<int, int>> trace[501];
		dijkstra(adj, trace, dist, src);
		erase_paths(adj, trace, dest);
		for(int i = 0; i < n; ++i){
			dist[i] = numeric_limits<int>::max();
		}
		dist[src] = 0;
		for(int i = 0; i <= 500; ++i){
			trace[i].clear();
		}
		dijkstra(adj, trace, dist, src);
		printf("%d\n", (dist[dest] == numeric_limits<int>::max() ? -1 : dist[dest]));
	}
	return 0;
}

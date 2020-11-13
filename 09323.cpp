#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

double best_cost(int s, int p, int y, int c, int d){
	return min(100 * (s + p * d), c * (y + p * d)) / 100.0;
}

double dijkstra(vector<vector<pair<int, double>>> &adj, int n, int start, int end){
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	vector<double> dist(n + 1, numeric_limits<double>::max());
	pq.push(make_pair(0.0, start));
	dist[start] = 0.0;
	while(!pq.empty()){
		int u = pq.top().second;
		if(u == end){
			return dist[u];
		}
		pq.pop();
		for(auto tmp : adj[u]){
			int v = tmp.first;
			double w = tmp.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return -1;
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int a0 = 0; a0 < tc; ++a0){
		int n, m, start, end, s, p, y;
		scanf("%d %d %d %d %d %d %d", &n, &m, &start, &end, &s, &p, &y);
		vector<vector<pair<int, double>>> adj(n + 1);
		for(int a1 = 0; a1 < m; ++a1){
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			double cost = best_cost(s, p, y, c, d);
			adj[a].push_back(make_pair(b, cost));
			adj[b].push_back(make_pair(a, cost));
		}
		double ans = dijkstra(adj, n, start, end);
		printf("%.2f\n", round(ans * 100) / 100);
	}
	return 0;
}

#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

double dijkstra(int n, int src, int dest, vector<vector<pair<double, int>>> &edges, double dist[101]){
	priority_queue<pair<double, int>> pq;
	pq.push(make_pair(1.0, src));
	while(!pq.empty()){
		pair<double, int> tmp = pq.top();
		pq.pop();
		double cost = tmp.first;
		int u = tmp.second;
		for(int j = 0; j < edges[u].size(); ++j){
			double cmp = cost * edges[u][j].first;
			if(cmp > dist[edges[u][j].second]){
				dist[edges[u][j].second] = cmp;
				pq.push(make_pair(cmp, edges[u][j].second));
			}
		}
	}
	return dist[dest];
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		double edge[101][101] = {};
		int x, y;
		scanf("%d %d", &x, &y);
		int m;
		scanf("%d", &m);
		for(int e = 0; e < m; ++e){
			int a, b;
			double p;
			scanf("%d %d %lf", &a, &b, &p);
			if(edge[a][b] < p){
				edge[a][b] = p;
			}
		}
		vector<vector<pair<double, int>>> edges;
		vector<pair<double, int>> tmp;
		edges.push_back(tmp);
		double dist[101] = {};
		for(int u = 1; u <= n; ++u){
			tmp.clear();
			for(int v = 1; v <= n; ++v){
				if(edge[u][v] != 0){
					tmp.push_back(make_pair(edge[u][v], v));
				}
			}
			edges.push_back(tmp);
			dist[u] = 0;
		}
		dist[x] = 1;
		printf("Case %d: %f\n", a0, dijkstra(n, x, y, edges, dist));
	}
	return 0;
}

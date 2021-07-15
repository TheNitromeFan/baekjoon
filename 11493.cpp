#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 1003
#define MAXF 1000000000

using namespace std;

void floyd_warshall(int adj[][MAXN], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

void spfa(vector<vector<int>> &graph, int p[][MAXN], int c[][MAXN], int f[][MAXN], vector<int> &dist, vector<int> &prev, int src){
	queue<int> q;
	vector<bool> queued(MAXN);
	q.push(src);
	dist[src] = 0;
	prev[src] = 0;
	queued[src] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		queued[u] = false;
		for(int v : graph[u]){
			if(c[u][v] > f[u][v] && dist[v] > dist[u] + p[u][v]){
				dist[v] = dist[u] + p[u][v];
				prev[v] = u;
				if(!queued[v]){
					q.push(v);
					queued[v] = true;
				}
			}
		}
	}
}

int mcmf(vector<vector<int>> &graph, int p[][MAXN], int c[][MAXN], int src, int dest){
	int ret = 0;
	int f[MAXN][MAXN] = {};
	vector<int> dist(MAXN), prev(MAXN);
	while(true){
		fill(dist.begin(), dist.end(), MAXF);
		fill(prev.begin(), prev.end(), -1);
		spfa(graph, p, c, f, dist, prev, src);
		if(prev[dest] == -1){
			break;
		}
		int flow = MAXF;
		int v = dest;
		while(v != src){
			int u = prev[v];
			flow = min(flow, c[u][v] - f[u][v]);
			v = u;
		}
		v = dest;
		while(v != src){
			int u = prev[v];
			ret += flow * p[u][v];
			f[u][v] += flow;
			f[v][u] -= flow;
			v = u;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		int adj[MAXN][MAXN];
		for(int u = 1; u <= n; ++u){
			for(int v = 1; v <= n; ++v){
				if(u == v){
					adj[u][v] = 0;
				}else{
					adj[u][v] = MAXF;
				}
			}
		}
		for(int a1 = 0; a1 < m; ++a1){
			int u, v;
			cin >> u >> v;
			adj[u][v] = 1;
			adj[v][u] = 1;
		}
		floyd_warshall(adj, n);
		vector<vector<int>> graph(MAXN);
		int cost[MAXN][MAXN] = {}, cap[MAXN][MAXN] = {};
		for(int u = 1; u <= n; ++u){
			int ci;
			cin >> ci;
			if(ci){
				graph[0].push_back(u);
				graph[u].push_back(0);
				cap[0][u] = 1;
			}
		}
		for(int v = n + 1; v <= n + n; ++v){
			int di;
			cin >> di;
			if(di){
				for(int u : graph[0]){
					graph[u].push_back(v);
					graph[v].push_back(u);
					cost[u][v] = adj[u][v - n];
					cost[v][u] = -adj[u][v - n];
					cap[u][v] = MAXF;
				}
				graph[v].push_back(2 * n + 1);
				graph[2 * n + 1].push_back(v);
				cap[v][2 * n + 1] = 1;
			}
		}
		cout << mcmf(graph, cost, cap, 0, 2 * n + 1) << '\n';
	}
	return 0;
}

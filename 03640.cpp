#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 2005
#define MAXF 2000000000

using namespace std;

void spfa(vector<vector<int>> &adj, int p[][MAXN], int c[][MAXN], int f[][MAXN], vector<int> &prev, int n){
	queue<int> q;
	vector<int> dist(2 * n + 2, MAXF);
	vector<bool> queued(2 * n + 2);
	q.push(0);
	dist[0] = 0;
	prev[0] = 0;
	queued[0] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		queued[u] = false;
		for(int v : adj[u]){
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

int min_cut_max_flow(vector<vector<int>> &adj, int p[][MAXN], int c[][MAXN], int n){
	int ret = 0;
	int f[MAXN][MAXN] = {};
	vector<int> prev(2 * n + 2);
	while(true){
		fill(prev.begin(), prev.end(), -1);
		spfa(adj, p, c, f, prev, n);
		if(prev[2 * n + 1] == -1){
			break;
		}
		int flow = MAXF;
		int v = 2 * n + 1;
		while(v != 0){
			int u = prev[v];
			flow = min(flow, c[u][v] - f[u][v]);
			v = u;
		}
		v = 2 * n + 1;
		while(v != 0){
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
	int n;
	while(cin >> n){
		int m;
		cin >> m;
		vector<vector<int>> adj(2 * n + 2);
		int p[MAXN][MAXN] = {}, c[MAXN][MAXN] = {};
		adj[0].push_back(1);
		adj[1].push_back(0);
		c[0][1] = 2;
		adj[1].push_back(2);
		adj[2].push_back(1);
		c[1][2] = 2;
		adj[2 * n - 1].push_back(2 * n);
		adj[2 * n].push_back(2 * n - 1);
		c[2 * n - 1][2 * n] = 2;
		adj[2 * n].push_back(2 * n + 1);
		adj[2 * n + 1].push_back(2 * n);
		c[2 * n][2 * n + 1] = 2;
		for(int i = 2; i < n; ++i){
			adj[2 * i - 1].push_back(2 * i);
			adj[2 * i].push_back(2 * i - 1);
			c[2 * i - 1][2 * i] = 1;
		}
		for(int a0 = 0; a0 < m; ++a0){
			int u, v, w;
			cin >> u >> v >> w;
			adj[2 * u].push_back(2 * v - 1);
			adj[2 * v - 1].push_back(2 * u);
			p[2 * u][2 * v - 1] += w;
			p[2 * v - 1][2 * u] -= w;
			c[2 * u][2 * v - 1] = 1;
		}
		cout << min_cut_max_flow(adj, p, c, n) << '\n';
	}
	return 0;
}

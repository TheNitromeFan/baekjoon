#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAXN 805
#define MAXF 2000000000

using namespace std;

void spfa(vector<vector<int>> &adj, int p[][MAXN], int c[][MAXN], int f[][MAXN], vector<int> &dist, vector<int> &prev, int src){
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

void mcmf(vector<vector<int>> &adj, int p[][MAXN], int c[][MAXN], int src, int dest, int &cnt, int &ans){
	vector<int> dist(MAXN), prev(MAXN);
	int f[MAXN][MAXN] = {};
	while(true){
		fill(dist.begin(), dist.end(), MAXF);
		fill(prev.begin(), prev.end(), -1);
		spfa(adj, p, c, f, dist, prev, src);
		if(prev[dest] == -1){
			break;
		}
		++cnt;
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
			ans += flow * p[u][v];
			f[u][v] += flow;
			f[v][u] -= flow;
			v = u;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(MAXN);
	int p[MAXN][MAXN] = {}, c[MAXN][MAXN] = {};
	for(int u = 1; u <= n; ++u){
		int k;
		cin >> k;
		for(int i = 0; i < k; ++i){
			int v, pay;
			cin >> v >> pay;
			adj[u].push_back(v + n);
			adj[v + n].push_back(u);
			p[u][v + n] = pay;
			p[v + n][u] = -pay;
			c[u][v + n] = 1;
		}
	}
	for(int u = 1; u <= n; ++u){
		adj[0].push_back(u);
		adj[u].push_back(0);
		c[0][u] = 1;
	}
	for(int v = n + 1; v <= n + m; ++v){
		adj[v].push_back(n + m + 1);
		adj[n + m + 1].push_back(v);
		c[v][n + m + 1] = 1;
	}
	int cnt = 0, ans = 0;
	mcmf(adj, p, c, 0, n + m + 1, cnt, ans);
	cout << cnt << '\n' << ans << '\n';
	return 0;
}

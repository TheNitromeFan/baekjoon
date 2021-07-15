#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 801

using namespace std;

bool bfs(vector<vector<int>> &adj, int c[][MAX], int f[][MAX], vector<int> &prev, int src, int dest){
	queue<int> q;
	q.push(src);
	prev[src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == dest){
			return true;
		}
		for(int v : adj[u]){
			if(c[u][v] > f[u][v] && prev[v] == -1){
				q.push(v);
				prev[v] = u;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(2 * n + 1);
	int capacity[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[n + u].push_back(v);
		adj[v].push_back(n + u);
		capacity[n + u][v] = 1;
		adj[n + v].push_back(u);
		adj[u].push_back(n + v);
		capacity[n + v][u] = 1;
	}
	for(int u = 1; u <= n; ++u){
		adj[u].push_back(n + u);
		adj[n + u].push_back(u);
		capacity[u][n + u] = 1;
	}
	int f[MAX][MAX] = {};
	vector<int> prev(2 * n + 1, -1);
	int flow = 0;
	while(bfs(adj, capacity, f, prev, n + 1, 2)){
		int c = 2000000000;
		int v = 2;
		while(v != n + 1){
			int u = prev[v];
			c = min(c, capacity[u][v] - f[u][v]);
			v = u;
		}
		v = 2;
		while(v != n + 1){
			int u = prev[v];
			f[u][v] += c;
			f[v][u] -= c;
			v = u;
		}
		flow += c;
		fill(prev.begin(), prev.end(), -1);
	}
	cout << flow << '\n';
	return 0;
}

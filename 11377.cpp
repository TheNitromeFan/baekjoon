#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2005

using namespace std;

bool bfs(vector<vector<int>> &adj, int c[][MAX], int f[][MAX], vector<int> &prev, int src, int dest){
	queue<int> q;
	prev[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == dest){
			return true;
		}
		for(int v : adj[u]){
			if(c[u][v] > f[u][v] && prev[v] == -1){
				prev[v] = u;
				q.push(v);
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n + m + 3);
	int capacity[MAX][MAX] = {};
	for(int u = 1; u <= n; ++u){
		int t;
		cin >> t;
		for(int j = 0; j < t; ++j){
			int v;
			cin >> v;
			adj[u].push_back(v + n);
			adj[v + n].push_back(u);
			capacity[u][v + n] = 1;
		}
	}
	for(int u = 1; u <= n; ++u){
		adj[0].push_back(u);
		adj[u].push_back(0);
		capacity[0][u] = 1;
	}
	for(int v = n + 1; v <= n + m; ++v){
		adj[v].push_back(n + m + 1);
		adj[n + m + 1].push_back(v);
		capacity[v][n + m + 1] = 1;
	}
	adj[0].push_back(n + m + 2);
	adj[n + m + 2].push_back(0);
	capacity[0][n + m + 2] = k;
	for(int u = 1; u <= n; ++u){
		adj[n + m + 2].push_back(u);
		adj[u].push_back(n + m + 2);
		capacity[n + m + 2][u] = 1;
	}
	int f[MAX][MAX] = {};
	vector<int> prev(n + m + 3, -1);
	int flow = 0;
	while(bfs(adj, capacity, f, prev, 0, n + m + 1)){
		int c = 2000000000;
		int v = n + m + 1;
		while(v != 0){
			int u = prev[v];
			c = min(c, capacity[u][v] - f[u][v]);
			v = u;
		}
		v = n + m + 1;
		while(v != 0){
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

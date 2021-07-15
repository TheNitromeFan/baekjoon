#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 150

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
	int n;
	cin >> n;
	vector<vector<int>> adj(MAX);
	int capacity[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		char u, v;
		int w;
		cin >> u >> v >> w;
		adj[(int)u].push_back((int)v);
		adj[(int)v].push_back((int)u);
		capacity[(int)u][(int)v] += w;
		capacity[(int)v][(int)u] += w;
	}
	vector<int> prev(MAX, -1);
	int f[MAX][MAX] = {};
	int flow = 0;
	while(bfs(adj, capacity, f, prev, 'A', 'Z')){
		int v = 'Z';
		int c = MAX * MAX * MAX;
		while(v != 'A'){
			int u = prev[v];
			c = min(c, capacity[u][v] - f[u][v]);
			v = u;
		}
		v = 'Z';
		while(v != 'A'){
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

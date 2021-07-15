#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 401

using namespace std;

bool bfs(vector<vector<int>> &adj_vec, int c[][MAX], int f[][MAX], vector<int> &prev, int n, int src, int dest){
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == dest){
			return true;
		}
		for(int v : adj_vec[u]){
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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj_vec(n + 1);
	int capacity[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj_vec[u].push_back(v);
		adj_vec[v].push_back(u);
		capacity[u][v] = 1;
	}
	vector<int> prev(n + 1, -1);
	int f[MAX][MAX] = {};
	int flow = 0;
	while(bfs(adj_vec, capacity, f, prev, n, 1, 2)){
		int v = 2;
		int c = MAX * MAX * MAX;
		while(v != 1){
			int u = prev[v];
			c = min(c, capacity[u][v] - f[u][v]);
			v = u;
		}
		v = 2;
		while(v != 1){
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

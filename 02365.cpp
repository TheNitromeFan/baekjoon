#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 200
#define MAXF 2000000000

using namespace std;

bool bfs(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], vector<int> &prev, int src, int dest){
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

int edmonds_karp(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], int sz, int src, int dest){
	int max_flow = 0;
	while(true){
		vector<int> prev(sz, -1);
		if(!bfs(adj, c, f, prev, src, dest)){
			break;
		}
		int v = dest;
		int flow = MAXF;
		while(v != src){
			int u = prev[v];
			flow = min(flow, c[u][v] - f[u][v]);
			v = u;
		}
		v = dest;
		while(v != src){
			int u = prev[v];
			f[u][v] += flow;
			f[v][u] -= flow;
			v = u;
		}
		max_flow += flow;
	}
	return max_flow;
}

int bin_search(vector<vector<int>> &adj, vector<int> &cols, vector<int> &rows, int cap[][MAXN], int n, int sum){
	int low = 0, high = MAXF;
	while(low < high){
		int mid = (low + high) / 2;
		vector<vector<int>> adj_copy = adj;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				adj[i].push_back(n + j);
				adj[n + j].push_back(i);
				cap[i][n + j] = mid;
			}
		}
		int f[MAXN][MAXN] = {};
		int max_flow = edmonds_karp(adj, cap, f, 2 * n + 2, 2 * n, 2 * n + 1);
		if(max_flow == sum){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return high;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cols(n), rows(n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> cols[i];
		sum += cols[i];
	}
	for(int j = 0; j < n; ++j){
		cin >> rows[j];
	}
	vector<vector<int>> adj(2 * n + 2);
	int cap[MAXN][MAXN] = {};
	for(int i = 0; i < n; ++i){
		adj[2 * n].push_back(i);
		adj[i].push_back(2 * n);
		cap[2 * n][i] = cols[i];
	}
	for(int j = 0; j < n; ++j){
		adj[n + j].push_back(2 * n + 1);
		adj[2 * n + 1].push_back(n + j);
		cap[n + j][2 * n + 1] = rows[j];
	}
	int k = bin_search(adj, cols, rows, cap, n, sum);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			adj[i].push_back(n + j);
			adj[n + j].push_back(i);
			cap[i][n + j] = k;
		}
	}
	int f[MAXN][MAXN] = {};
	edmonds_karp(adj, cap, f, 2 * n + 2, 2 * n, 2 * n + 1);
	cout << k << '\n';
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << f[i][n + j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

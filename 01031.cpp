#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 55
#define MAXF 2000000000

using namespace std;

bool bfs(vector<vector<int>> &adj, int c[][2 * MAXN], int f[][2 * MAXN], vector<int> &prev, int n, int m){
	queue<int> q;
	q.push(n + m);
	prev[n + m] = n + m;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == n + m + 1){
			return true;
		}
		for(int v : adj[u]){
			if(prev[v] == -1 && c[u][v] > f[u][v]){
				q.push(v);
				prev[v] = u;
			}
		}
	}
	return false;
}

int max_flow(vector<vector<int>> &adj, int c[][2 * MAXN], int f[][2 * MAXN], int n, int m){
	int ret = 0;
	vector<int> prev(n + m + 2);
	while(true){
		fill(prev.begin(), prev.end(), -1);
		if(!bfs(adj, c, f, prev, n, m)){
			break;
		}
		int flow = MAXF;
		int v = n + m + 1;
		while(v != n + m){
			int u = prev[v];
			flow = min(flow, c[u][v] - f[u][v]);
			v = u;
		}
		v = n + m + 1;
		while(v != n + m){
			int u = prev[v];
			f[u][v] += flow;
			f[v][u] -= flow;
			v = u;
		}
		ret += flow;
	}
	return ret;
}

bool bfs1(vector<vector<int>> &adj, int c[][2 * MAXN], int f[][2 * MAXN], vector<int> &prev, int n, int m, int i, int j){
	queue<int> q;
	q.push(n + m);
	prev[n + m] = n + m;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == n + m + 1){
			return true;
		}
		for(int v : adj[u]){
			if((u == i && v == j) || (u == j && v == i) || ((u < i || (u == i && v < j)) && f[u][v] == 0)){
				continue;
			}
			if(prev[v] == -1 && c[u][v] > f[u][v]){
				q.push(v);
				prev[v] = u;
			}
		}
	}
	return false;
}

int max_flow1(vector<vector<int>> &adj, int c[][2 * MAXN], int f[][2 * MAXN], int n, int m, int i, int j){
	f[i][j] = 0;
	f[j][i] = 1;
	--f[n + m][i];
	++f[i][n + m];
	--f[j][n + m + 1];
	++f[n + m + 1][j];
	int ret = 0;
	vector<int> prev(n + m + 2);
	while(true){
		fill(prev.begin(), prev.end(), -1);
		if(!bfs1(adj, c, f, prev, n, m, i, j)){
			break;
		}
		int flow = MAXF;
		int v = n + m + 1;
		while(v != n + m){
			int u = prev[v];
			flow = min(flow, c[u][v] - f[u][v]);
			v = u;
		}
		v = n + m + 1;
		while(v != n + m){
			int u = prev[v];
			f[u][v] += flow;
			f[v][u] -= flow;
			v = u;
		}
		ret += flow;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + m + 2);
	int c[2 * MAXN][2 * MAXN] = {};
	for(int i = 0; i < n; ++i){
		for(int j = n; j < n + m; ++j){
			adj[i].push_back(j);
			adj[j].push_back(i);
			c[i][j] = 1;
		}
	}
	int sum_x = 0, sum_y = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		adj[n + m].push_back(i);
		adj[i].push_back(n + m);
		c[n + m][i] = x;
		sum_x += x;
	}
	for(int j = n; j < n + m; ++j){
		int y;
		cin >> y;
		adj[j].push_back(n + m + 1);
		adj[n + m + 1].push_back(j);
		c[j][n + m + 1] = y;
		sum_y += y;
	}
	int f[2 * MAXN][2 * MAXN] = {};
	int mf = max_flow(adj, c, f, n, m);
	if(mf == sum_x && mf == sum_y){
		for(int i = 0; i < n; ++i){
			for(int j = n; j < n + m; ++j){
				if(f[i][j] && !max_flow1(adj, c, f, n, m, i, j)){
					f[i][j] = 1;
					f[j][i] = 0;
					++f[n + m][i];
					--f[i][n + m];
					++f[j][n + m + 1];
					--f[n + m + 1][j];
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = n; j < n + m; ++j){
				cout << f[i][j];
			}
			cout << '\n';
		}
	}else{
		cout << -1 << '\n';
	}
	return 0;
}

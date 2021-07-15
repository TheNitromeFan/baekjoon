#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 410
#define MAXF 2000000000

using namespace std;

bool bfs(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], vector<int> &level, int src, int dest){
	queue<int> q;
	q.push(src);
	level[src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(level[v] == -1 && c[u][v] > f[u][v]){
				q.push(v);
				level[v] = level[u] + 1;
			}
		}
	}
	return level[dest] != -1;
}

int dfs(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], vector<int> &level, vector<unsigned> &ptr, int dest, int u, int pushed){
	if(pushed == 0){
		return 0;
	}else if(u == dest){
		return pushed;
	}
	while(ptr[u] < adj[u].size()){
		int v = adj[u][ptr[u]];
		++ptr[u];
		if(level[v] == level[u] + 1 && c[u][v] > f[u][v]){
			int tr = dfs(adj, c, f, level, ptr, dest, v, min(pushed, c[u][v] - f[u][v]));
			if(tr > 0){
				f[u][v] += tr;
				f[v][u] -= tr;
				return tr;
			}
		}
	}
	return 0;
}

void dinic(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], int src, int dest){
	vector<int> level(MAXN);
	vector<unsigned> ptr(MAXN);
	while(true){
		fill(level.begin(), level.end(), -1);
		if(!bfs(adj, c, f, level, src, dest)){
			break;
		}
		fill(ptr.begin(), ptr.end(), 0);
		while(true){
			int pushed = dfs(adj, c, f, level, ptr, dest, src, MAXF);
			if(pushed == 0){
				break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, src, dest;
	cin >> n >> m >> src >> dest;
	src = 2 * src - 1;
	dest = 2 * dest;
	vector<vector<int>> adj(MAXN);
	int c[MAXN][MAXN] = {}, f[MAXN][MAXN] = {};
	for(int u = 1; u <= n; ++u){
		int x;
		cin >> x;
		adj[2 * u - 1].push_back(2 * u);
		adj[2 * u].push_back(2 * u - 1);
		c[2 * u - 1][2 * u] = x;
	}
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[2 * u].push_back(2 * v - 1);
		adj[2 * v - 1].push_back(2 * u);
		c[2 * u][2 * v - 1] = MAXF;
		adj[2 * v].push_back(2 * u - 1);
		adj[2 * u - 1].push_back(2 * v);
		c[2 * v][2 * u - 1] = MAXF;
	}
	dinic(adj, c, f, src, dest);
	queue<int> q;
	vector<bool> visited(MAXN);
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		visited[u] = true;
		for(int v : adj[u]){
			if(!visited[v] && c[u][v] > f[u][v]){
				q.push(v);
			}
		}
	}
	for(int u = 1; u <= n; ++u){
		if(visited[2 * u - 1] && !visited[2 * u]){
			cout << u << ' ';
		}
	}
	return 0;
}

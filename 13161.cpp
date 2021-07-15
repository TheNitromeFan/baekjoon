#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 502
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

int dinic(vector<vector<int>> &adj, int cap[][MAXN], int f[][MAXN], int src, int dest){
	int ret = 0;
	vector<int> level(MAXN);
	vector<unsigned> ptr(MAXN);
	while(true){
		fill(level.begin(), level.end(), -1);
		if(!bfs(adj, cap, f, level, src, dest)){
			break;
		}
		fill(ptr.begin(), ptr.end(), 0);
		while(true){
			int pushed = dfs(adj, cap, f, level, ptr, dest, src, MAXF);
			if(pushed == 0){
				break;
			}
			ret += pushed;
		}
	}
	return ret;
}

void recover(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], vector<bool> &visited, int src){
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v] && c[u][v] > f[u][v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(MAXN);
	int cap[MAXN][MAXN] = {};
	for(int u = 1; u <= n; ++u){
		int x;
		cin >> x;
		if(x == 1){
			adj[0].push_back(u);
			adj[u].push_back(0);
			cap[0][u] = MAXF;
		}else if(x == 2){
			adj[u].push_back(n + 1);
			adj[n + 1].push_back(u);
			cap[u][n + 1] = MAXF;
		}
	}
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= n; ++v){
			cin >> cap[u][v];
			if(u != v){
				adj[u].push_back(v);
			}
		}
	}
	int f[MAXN][MAXN] = {};
	int ans = dinic(adj, cap, f, 0, n + 1);
	vector<bool> visited(MAXN);
	recover(adj, cap, f, visited, 0);
	vector<int> a, b;
	for(int u = 1; u <= n; ++u){
		if(visited[u]){
			a.push_back(u);
		}else{
			b.push_back(u);
		}
	}
	cout << ans << '\n';
	for(int x : a){
		cout << x << ' ';
	}
	cout << '\n';
	for(int y : b){
		cout << y << ' ';
	}
	cout << '\n';
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#define MAXN 101
#define MAX 20200
#define MAXF 2000000000

using namespace std;

bool bfs(vector<vector<int>> &adj, map<pair<int, int>, int> &c, map<pair<int, int>, int> &f, vector<int> &level, int src, int dest){
	queue<int> q;
	q.push(src);
	level[src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(level[v] == -1 && c[make_pair(u, v)] > f[make_pair(u, v)]){
				q.push(v);
				level[v] = level[u] + 1;
			}
		}
	}
	return level[dest] != -1;
}

int dfs(vector<vector<int>> &adj, map<pair<int, int>, int> &c, map<pair<int, int>, int> &f, vector<int> &level, vector<unsigned> &ptr, int dest, int u, int pushed){
	if(pushed == 0){
		return 0;
	}else if(u == dest){
		return pushed;
	}
	while(ptr[u] < adj[u].size()){
		int v = adj[u][ptr[u]];
		++ptr[u];
		if(level[v] == level[u] + 1 && c[make_pair(u, v)] > f[make_pair(u, v)]){
			int tr = dfs(adj, c, f, level, ptr, dest, v, min(pushed, c[make_pair(u, v)] - f[make_pair(u, v)]));
			if(tr > 0){
				f[make_pair(u, v)] += tr;
				f[make_pair(v, u)] -= tr;
				return tr;
			}
		}
	}
	return 0;
}

int dinic(vector<vector<int>> &adj, map<pair<int, int>, int> &cap, int src, int dest){
	int ret = 0;
	map<pair<int, int>, int> f;
	vector<int> level(MAX);
	vector<unsigned> ptr(MAX);
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

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char board[MAXN][MAXN];
	int srcx = -1, srcy = -1, src = -1, destx = -1, desty = -1, dest = -1;
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
		for(int j = 0; j < m; ++j){
			if(board[i][j] == 'K'){
				srcx = i;
				srcy = j;
				src = 2 * (i * m + j) + 1;
			}else if(board[i][j] == 'H'){
				destx = i;
				desty = j;
				dest = 2 * (i * m + j);
			}
		}
	}
	if(src == -1 || dest == -1 || abs(srcx - destx) + abs(srcy - desty) <= 1){
		printf("-1\n");
		return 0;
	}
	vector<vector<int>> adj(MAX);
	map<pair<int, int>, int> c;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			adj[2 * (i * m + j)].push_back(2 * (i * m + j) + 1);
			adj[2 * (i * m + j) + 1].push_back(2 * (i * m + j));
			c[make_pair(2 * (i * m + j), 2 * (i * m + j) + 1)] = 1;
			c[make_pair(2 * (i * m + j) + 1, 2 * (i * m + j))] = 0;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i + 1 < n && board[i][j] != '#' && board[i + 1][j] != '#'){
				adj[2 * (i * m + j) + 1].push_back(2 * ((i + 1) * m + j));
				adj[2 * ((i + 1) * m + j)].push_back(2 * (i * m + j) + 1);
				c[make_pair(2 * (i * m + j) + 1, 2 * ((i + 1) * m + j))] = MAXF;
				c[make_pair(2 * ((i + 1) * m + j), 2 * (i * m + j) + 1)] = 0;
				adj[2 * ((i + 1) * m + j) + 1].push_back(2 * (i * m + j));
				adj[2 * (i * m + j)].push_back(2 * ((i + 1) * m + j) + 1);
				c[make_pair(2 * ((i + 1) * m + j) + 1, 2 * (i * m + j))] = MAXF;
				c[make_pair(2 * (i * m + j), 2 * ((i + 1) * m + j) + 1)] = 0;
			}
			if(j + 1 < m && board[i][j] != '#' && board[i][j + 1] != '#'){
				adj[2 * (i * m + j) + 1].push_back(2 * (i * m + j + 1));
				adj[2 * (i * m + j + 1)].push_back(2 * (i * m + j) + 1);
				c[make_pair(2 * (i * m + j) + 1, 2 * (i * m + j + 1))] = MAXF;
				c[make_pair(2 * (i * m + j + 1), 2 * (i * m + j) + 1)] = 0;
				adj[2 * (i * m + j + 1) + 1].push_back(2 * (i * m + j));
				adj[2 * (i * m + j)].push_back(2 * (i * m + j + 1) + 1);
				c[make_pair(2 * (i * m + j + 1) + 1, 2 * (i * m + j))] = MAXF;
				c[make_pair(2 * (i * m + j), 2 * (i * m + j + 1) + 1)] = 0;
			}
		}
	}
	printf("%d\n", dinic(adj, c, src, dest));
	return 0;
}

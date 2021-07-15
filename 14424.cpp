#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 202
#define MAXF 2000000000

using namespace std;

void spfa(vector<vector<int>> &adj, int p[][MAXN * MAXN], int c[][MAXN * MAXN], int f[][MAXN * MAXN], vector<int> &dist, vector<int> &prev, int src){
	queue<int> q;
	vector<bool> queued(MAXN * MAXN);
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

int mcmf(vector<vector<int>> &adj, int p[][MAXN * MAXN], int c[][MAXN * MAXN], int src, int dest){
	vector<int> dist(MAXN * MAXN), prev(MAXN * MAXN);
	int f[MAXN * MAXN][MAXN * MAXN] = {};
	int ans = 0;
	while(true){
		fill(dist.begin(), dist.end(), MAXF);
		fill(prev.begin(), prev.end(), -1);
		spfa(adj, p, c, f, dist, prev, src);
		if(prev[dest] == -1){
			break;
		}
		int new_ans = ans;
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
			new_ans += flow * p[u][v];
			f[u][v] += flow;
			f[v][u] -= flow;
			v = u;
		}
		if(new_ans > ans){
			break;
		}
		ans = new_ans;
	}
	return ans;
}

int main(){
	int scores[6][6] =
	{
		{10, 8, 7, 5, 0, 1},
		{8, 6, 4, 3, 0, 1},
		{7, 4, 3, 2, 0, 1},
		{5, 3, 2, 2, 0, 1},
		{0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 0}
	};
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAXN][MAXN];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	vector<vector<int>> adj(MAXN * MAXN);
	int p[MAXN * MAXN][MAXN * MAXN] = {}, c[MAXN * MAXN][MAXN * MAXN] = {};
	for(int x = 0; x < n; ++x){
		for(int y = x % 2; y < m; y += 2){
			for(int i = 0; i < 4; ++i){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m){
					adj[x * m + y].push_back(nx * m + ny);
					adj[nx * m + ny].push_back(x * m + y);
					p[x * m + y][nx * m + ny] = -scores[map[x][y] - 'A'][map[nx][ny] - 'A'];
					p[nx * m + ny][x * m + y] = scores[map[x][y] - 'A'][map[nx][ny] - 'A'];
					c[x * m + y][nx * m + ny] = 1;
				}
			}
		}
	}
	for(int x = 0; x < n; ++x){
		for(int y = x % 2; y < m; y += 2){
			adj[n * m].push_back(x * m + y);
			adj[x * m + y].push_back(n * m);
			c[n * m][x * m + y] = 1;
		}
	}
	for(int x = 0; x < n; ++x){
		for(int y = 1 - x % 2; y < m; y += 2){
			adj[x * m + y].push_back(n * m + 1);
			adj[n * m + 1].push_back(x * m + y);
			c[x * m + y][n * m + 1] = 1;
		}
	}
	printf("%d\n", -mcmf(adj, p, c, n * m, n * m + 1));
	return 0;
}

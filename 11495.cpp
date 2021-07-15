#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 51
#define MAX 3000
#define MAXF 2000000000

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
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		int board[MAXN][MAXN];
		int ans = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> board[i][j];
				ans += board[i][j];
			}
		}
		vector<vector<int>> adj(n * m + 2);
		int capacity[MAX][MAX] = {};
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		for(int x = 0; x < n; ++x){
			for(int y = x % 2; y < m; y += 2){
				for(int i = 0; i < 4; ++i){
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m){
						adj[x * m + y].push_back(nx * m + ny);
						adj[nx * m + ny].push_back(x * m + y);
						capacity[x * m + y][nx * m + ny] = MAXF;
					}
				}
			}
		}
		for(int x = 0; x < n; ++x){
			for(int y = x % 2; y < m; y += 2){
				adj[n * m].push_back(x * m + y);
				adj[x * m + y].push_back(n * m);
				capacity[n * m][x * m + y] = board[x][y];
			}
		}
		for(int x = 0; x < n; ++x){
			for(int y = 1 - x % 2; y < m; y += 2){
				adj[x * m + y].push_back(n * m + 1);
				adj[n * m + 1].push_back(x * m + y);
				capacity[x * m + y][n * m + 1] = board[x][y];
			}
		}
		int flow[MAX][MAX] = {};
		vector<int> prev(n * m + 2, -1);
		while(bfs(adj, capacity, flow, prev, n * m, n * m + 1)){
			int f = MAXF;
			int v = n * m + 1;
			while(v != n * m){
				int u = prev[v];
				f = min(f, capacity[u][v] - flow[u][v]);
				v = u;
			}
			v = n * m + 1;
			while(v != n * m){
				int u = prev[v];
				flow[u][v] += f;
				flow[v][u] -= f;
				v = u;
			}
			ans -= f;
			fill(prev.begin(), prev.end(), -1);
		}
		cout << ans << '\n';
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1200
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
	int m, n;
	cin >> m >> n;
	vector<vector<int>> adj(m + n + 2);
	int capacity[MAX][MAX] = {};
	for(int v = 1; v <= m; ++v){
		int x;
		cin >> x;
		adj[v].push_back(m + n + 1);
		adj[m + n + 1].push_back(v);
		capacity[v][m + n + 1] = x;
	}
	vector<vector<int>> keys(m + 1);
	for(int u = m + 1; u <= m + n; ++u){
		int a;
		cin >> a;
		for(int i = 0; i < a; ++i){
			int v;
			cin >> v;
			keys[v].push_back(u);
			adj[u].push_back(v);
			adj[v].push_back(u);
			capacity[u][v] = MAXF;
		}
		int b;
		cin >> b;
		adj[0].push_back(u);
		adj[u].push_back(0);
		capacity[0][u] = b;
	}
	for(int v = 1; v <= m; ++v){
		for(unsigned idx1 = 0; idx1 < keys[v].size(); ++idx1){
			for(unsigned idx2 = 0; idx2 < idx1; ++idx2){
				int u1 = keys[v][idx1], u2 = keys[v][idx2];
				adj[u2].push_back(u1);
				adj[u1].push_back(u2);
				capacity[u1][u2] = MAXF;
			}
		}
	}
	int flow[MAX][MAX] = {};
	vector<int> prev(m + n + 2, -1);
	int ans = 0;
	while(bfs(adj, capacity, flow, prev, 0, m + n + 1)){
		int f = MAXF;
		int v = m + n + 1;
		while(v != 0){
			int u = prev[v];
			f = min(f, capacity[u][v] - flow[u][v]);
			v = u;
		}
		v = m + n + 1;
		while(v != 0){
			int u = prev[v];
			flow[u][v] += f;
			flow[v][u] -= f;
			v = u;
		}
		ans += f;
		fill(prev.begin(), prev.end(), -1);
	}
	cout << ans << '\n';
	return 0;
}

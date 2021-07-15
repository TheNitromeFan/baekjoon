#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAXN 301
#define MAXF 2000000000

using namespace std;

bool bfs(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], vector<int> &prev, int src, int dest){
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

void edmonds_karp(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], int n, int src, int dest){
 	while(true){
		vector<int> prev(n, -1);
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
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 0; a0 < k; ++a0){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		int capacity[MAXN][MAXN] = {};
		vector<pair<int, int>> edges(m);
		for(int i = 0; i < m; ++i){
			int from, to, bandwidth;
			cin >> from >> to >> bandwidth;
			adj[from].push_back(to);
			adj[to].push_back(from);
			capacity[from][to] += bandwidth;
			edges[i] = make_pair(from, to);
		}
		int f[MAXN][MAXN] = {};
		edmonds_karp(adj, capacity, f, n + 1, 1, n);
		int ans = 0;
		for(int i = 0; i < m; ++i){
			vector<int> prev(n + 1, -1);
			int from = edges[i].first, to = edges[i].second;
			queue<int> q;
			prev[from] = 0;
			q.push(from);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				if(u == to){
					break;
				}
				for(int v : adj[u]){
					if(capacity[u][v] > f[u][v] && prev[v] == -1){
						prev[v] = u;
						q.push(v);
					}
				}
			}
			if(prev[to] == -1){
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

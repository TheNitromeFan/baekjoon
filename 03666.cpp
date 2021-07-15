#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 205
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

long long edmonds_karp(vector<vector<int>> &adj, int c[][MAXN], int n, int src, int dest){
	int f[MAXN][MAXN] = {};
	long long ret = 0;
	while(true){
		vector<int> prev(2 * n + 2, -1);
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
		ret += flow;
	}
	return ret;
}

int binary_search(vector<vector<int>> &adj, int cap[][MAXN], vector<int> &a, vector<bool> &b, int n){
	int low = 0, high = MAXF, ans = 0;
	while(low < high){
		int k = (low + high) / 2;
		long long target_flow = 0;
		vector<vector<int>> adj_copy = adj;
		for(int i = 0; i < n; ++i){
			if(a[i] > 0 && b[i]){
				adj_copy[n + i].push_back(2 * n + 1);
				adj_copy[2 * n + 1].push_back(n + i);
				cap[n + i][2 * n + 1] = k;
				target_flow += k;
			}else if(a[i] > 0){
				adj_copy[n + i].push_back(2 * n + 1);
				adj_copy[2 * n + 1].push_back(n + i);
				cap[n + i][2 * n + 1] = 1;
				target_flow += 1;
			}
		}
		long long ek = edmonds_karp(adj_copy, cap, n, 2 * n, 2 * n + 1);
		if(ek == target_flow){
			ans = k;
			low = k + 1;
		}else{
			high = k;
		}
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		char map[MAXN][MAXN];
		for(int i = 0; i < n; ++i){
			scanf("%s", map[i]);
		}
		vector<vector<int>> adj(2 * n + 2);
		int cap[MAXN][MAXN] = {};
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(i == j || (a[i] > 0 && a[j] > 0 && map[i][j] == 'Y')){
					adj[i].push_back(n + j);
					adj[n + j].push_back(i);
					cap[i][n + j] = MAXF;
				}
			}
		}
		for(int i = 0; i < n; ++i){
			if(a[i] > 0){
				adj[2 * n].push_back(i);
				adj[i].push_back(2 * n);
				cap[2 * n][i] = a[i];
			}
		}
		vector<bool> border(n);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(i != j && a[i] > 0 && a[j] == 0 && map[i][j] == 'Y'){
					border[i] = true;
					break;
				}
			}
		}
		printf("%d\n", binary_search(adj, cap, a, border, n));
	}
	return 0;
}

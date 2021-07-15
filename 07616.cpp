#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 205
#define MAXF 2000000000

using namespace std;

bool bfs(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], vector<int> &prev, int n, int m){
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

int max_flow(vector<vector<int>> &adj, int c[][MAXN], int f[][MAXN], int n, int m){
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 0;
	while(true){
		int k, n;
		cin >> k >> n;
		if(k == 0 && n == 0){
			break;
		}
		++tc;
		vector<vector<int>> adj(n + 1);
		int c[MAXN][MAXN];
		for(int u = 1; u <= n; ++u){
			;
		}
	}
	return 0;
}

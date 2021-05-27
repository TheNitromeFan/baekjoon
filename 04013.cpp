#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void traverse(vector<int> &post_order, vector<vector<int>> &adj, vector<bool> &visited, int u){
	if(visited[u]){
		return;
	}
	visited[u] = true;
	for(int v : adj[u]){
		traverse(post_order, adj, visited, v);
	}
	post_order.push_back(u);
}

void assign(vector<vector<int>> &rev, vector<int> &assigned, int u, int root){
	if(assigned[u] != -1){
		return;
	}
	assigned[u] = root;
	for(int v : rev[u]){
		assign(rev, assigned, v, root);
	}
}

int bfs(vector<int> &dp, vector<vector<int>> &scc_adj, vector<int> &scc_cash, vector<bool> &scc_rest, int scc_start){
	queue<int> q;
	q.push(scc_start);
	dp[scc_start] = scc_cash[scc_start];
	int ret = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(scc_rest[u]){
			ret = max(ret, dp[u]);
		}
		for(int v : scc_adj[u]){
			if(dp[v] < dp[u] + scc_cash[v]){
				q.push(v);
				dp[v] = dp[u] + scc_cash[v];
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1), rev(n + 1);
	for(int a1 = 0; a1 < m; ++a1){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		rev[y].push_back(x);
	}
	vector<int> cash(n + 1);
	for(int u = 1; u <= n; ++u){
		cin >> cash[u];
	}
	vector<bool> visited(n + 1);
	vector<int> post_order;
	for(int u = 1; u <= n; ++u){
		traverse(post_order, adj, visited, u);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(n + 1, -1);
	int comp = 0;
	for(int u : post_order){
		if(assigned[u] == -1){
			++comp;
			assign(rev, assigned, u, comp);
		}
	}
	int s, p;
	cin >> s >> p;
	int scc_start = assigned[s];
	vector<bool> scc_rest(comp + 1);
	for(int a2 = 0; a2 < p; ++a2){
		int u;
		cin >> u;
		scc_rest[assigned[u]] = true;
	}
	vector<int> scc_cash(comp + 1);
	for(int u = 1; u <= n; ++u){
		scc_cash[assigned[u]] += cash[u];
	}
	vector<vector<int>> scc_adj(comp + 1);
	for(int u = 1; u <= n; ++u){
		for(int v : adj[u]){
			if(assigned[u] != assigned[v] && find(scc_adj[assigned[u]].begin(), scc_adj[assigned[u]].end(), assigned[v]) == scc_adj[assigned[u]].end()){
				scc_adj[assigned[u]].push_back(assigned[v]);
			}
		}
	}
	vector<int> dp(comp + 1);
	cout << bfs(dp, scc_adj, scc_cash, scc_rest, scc_start);
	return 0;
}

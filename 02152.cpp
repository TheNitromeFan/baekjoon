#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

void traverse(vector<vector<int>> &adj, vector<int> &post_order, vector<bool> &visited, int u){
	if(visited[u]){
		return;
	}
	visited[u] = true;
	for(int v : adj[u]){
		traverse(adj, post_order, visited, v);
	}
	post_order.push_back(u);
}

void assign_scc(vector<vector<int>> &rev, vector<int> &assigned, int v, int scc){
	if(assigned[v] != -1){
		return;
	}
	assigned[v] = scc;
	for(int u : rev[v]){
		assign_scc(rev, assigned, u, scc);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, src, tgt;
	cin >> n >> m >> src >> tgt;
	vector<vector<int>> adj(n + 1), rev(n + 1);
	vector<pair<int, int>> edges(m);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		rev[v].push_back(u);
		edges[i] = make_pair(u, v);
	}
	vector<bool> visited(n + 1);
	vector<int> post_order;
	for(int u = 1; u <= n; ++u){
		traverse(adj, post_order, visited, u);
	}
	reverse(post_order.begin(), post_order.end());
	int scc_count = 0;
	vector<int> scc(n + 1, -1);
	for(int v : post_order){
		if(scc[v] == -1){
			assign_scc(rev, scc, v, scc_count);
			++scc_count;
		}
	}
	vector<int> scc_vertex_count(scc_count);
	for(int u = 1; u <= n; ++u){
		int s = scc[u];
		++scc_vertex_count[s];
	}
	vector<vector<int>> scc_adj(scc_count);
	for(pair<int, int> edge : edges){
		int u = edge.first, v = edge.second;
		if(scc[u] != scc[v]){
			scc_adj[scc[u]].push_back(scc[v]);
		}
	}
	vector<vector<int>> scc_adj1(scc_count);
	vector<bool> visited1(scc_count);
	vector<int> indegree(scc_count);
	queue<int> q;
	q.push(scc[src]);
	visited1[scc[src]] = true;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int t : scc_adj[s]){
			scc_adj1[s].push_back(t);
			++indegree[t];
			if(!visited1[t]){
				q.push(t);
				visited1[t] = true;
			}
		}
	}
	vector<int> dp(scc_count);
	q.push(scc[src]);
	dp[scc[src]] = scc_vertex_count[scc[src]];
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int t : scc_adj1[s]){
			dp[t] = max(dp[t], dp[s] + scc_vertex_count[t]);
			--indegree[t];
			if(indegree[t] == 0){
				q.push(t);
			}
		}
	}
	cout << dp[scc[tgt]] << '\n';
	return 0;
}

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

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

void assign_scc(vector<vector<int>> &rev, vector<int> &scc, int v, int val){
	if(scc[v] != -1){
		return;
	}
	scc[v] = val;
	for(int u : rev[v]){
		assign_scc(rev, scc, u, val);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for(int a0 = 0; a0 < tc; ++a0){
		int n, m;
		long long report;
		cin >> n >> m >> report;
		vector<vector<int>> adj(n + 1), rev(n + 1);
		vector<pair<int, int>> edges(m);
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			rev[v].push_back(u);
			edges[i] = make_pair(u, v);
		}
		vector<long long> info(n + 1);
		for(int u = 1; u <= n; ++u){
			cin >> info[u];
		}
		vector<bool> visited(n + 1);
		vector<int> post_order;
		for(int u = 1; u <= n; ++u){
			traverse(adj, post_order, visited, u);
		}
		reverse(post_order.begin(), post_order.end());
		vector<int> scc(n + 1, -1);
		int scc_count = 0;
		for(int v : post_order){
			if(scc[v] == -1){
				assign_scc(rev, scc, v, scc_count);
				++scc_count;
			}
		}
		vector<vector<int>> scc_vertices(scc_count);
		for(int u = 1; u <= n; ++u){
			scc_vertices[scc[u]].push_back(u);
		}
		vector<vector<int>> scc_adj(scc_count);
		vector<int> indegree(scc_count);
		for(pair<int, int> edge : edges){
			int u = edge.first, v = edge.second;
			int s = scc[u], t = scc[v];
			if(s != t){
				scc_adj[s].push_back(t);
				++indegree[t];
			}
		}
		vector<long long> scc_info(scc_count);
		for(int s = 0; s < scc_count; ++s){
			long long g = 0;
			for(int u : scc_vertices[s]){
				g = gcd(g, info[u]);
			}
			scc_info[s] = g;
		}
		queue<int> q;
		for(int s = 0; s < scc_count; ++s)
		if(indegree[s] == 0){
			q.push(s);
		}
		unsigned ans = 0;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			if(scc_info[s] == report){
				ans += scc_vertices[s].size();
			}
			for(int t : scc_adj[s]){
				scc_info[t] = gcd(scc_info[t], scc_info[s]);
				--indegree[t];
				if(indegree[t] == 0){
					q.push(t);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

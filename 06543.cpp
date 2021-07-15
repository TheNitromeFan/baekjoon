#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

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

void assign_scc(vector<int> &assigned, vector<vector<int>> &rev, int v, int scc){
	if(assigned[v] != -1){
		return;
	}
	assigned[v] = scc;
	for(int u : rev[v]){
		assign_scc(assigned, rev, u, scc);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int m;
		cin >> m;
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
			traverse(post_order, adj, visited, u);
		}
		reverse(post_order.begin(), post_order.end());
		vector<int> scc(n + 1, -1);
		int scc_count = 0;
		for(int v : post_order){
			if(scc[v] == -1){
				assign_scc(scc, rev, v, scc_count);
				++scc_count;
			}
		}
		vector<bool> sink(scc_count, true);
		for(pair<int, int> edge : edges){
			int u = edge.first, v = edge.second;
			if(scc[u] != scc[v]){
				sink[scc[u]] = false;
			}
		}
		for(int u = 1; u <= n; ++u){
			if(sink[scc[u]]){
				cout << u << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}

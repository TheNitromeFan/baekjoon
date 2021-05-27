#include <iostream>
#include <vector>
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

void assign(vector<vector<int>> &rev, vector<int> &assigned, int u, int root){
	if(assigned[u] != -1){
		return;
	}
	assigned[u] = root;
	for(int v : rev[u]){
		assign(rev, assigned, v, root);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1), rev(n + 1);
		for(int a1 = 0; a1 < m; ++a1){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			rev[y].push_back(x);
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
		vector<bool> source(comp + 1, true);
		for(int u = 1; u <= n; ++u){
			for(int v : adj[u]){
				if(assigned[u] == assigned[v]){
					continue;
				}
				source[assigned[v]] = false;
			}
		}
		int cnt = 0;
		for(int c = 1; c <= comp; ++c){
			if(source[c]){
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

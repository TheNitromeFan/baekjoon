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

void assign(vector<vector<int>> &rev, vector<int> &assigned, int v, int c){
	if(assigned[v] != -1){
		return;
	}
	assigned[v] = c;
	for(int u : rev[v]){
		assign(rev, assigned, u, c);
	}
}

bool satisfiable(vector<vector<int>> &adj, vector<vector<int>> &rev, int n){
	vector<bool> visited(2 * n + 1);
	vector<int> post_order;
	for(int u = 1; u <= 2 * n; ++u){
		traverse(post_order, adj, visited, u);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(2 * n + 1, -1);
	int c = 0;
	for(int v : post_order){
		if(assigned[v] == -1){
			++c;
			assign(rev, assigned, v, c);
		}
	}
	for(int u = 1; u <= n; ++u){
		if(assigned[u] == assigned[2 * n + 1 - u]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while(cin >> n){
		cin >> m;
		vector<vector<int>> adj(2 * n + 1), rev(2 * n + 1);
		for(int a0 = 0; a0 < m; ++a0){
			int i, j;
			cin >> i >> j;
			if(i < 0){
				i += 2 * n + 1;
			}
			if(j < 0){
				j += 2 * n + 1;
			}
			adj[2 * n + 1 - i].push_back(j);
			rev[j].push_back(2 * n + 1 - i);
			adj[2 * n + 1 - j].push_back(i);
			rev[i].push_back(2 * n + 1 - j);
		}
		cout << satisfiable(adj, rev, n) << '\n';
	}
	return 0;
}

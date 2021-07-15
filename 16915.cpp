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

bool satisfiable(vector<vector<int>> &adj, vector<vector<int>> &rev, int m){
	vector<bool> visited(2 * m + 1);
	vector<int> post_order;
	for(int u = 1; u <= 2 * m; ++u){
		traverse(post_order, adj, visited, u);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(2 * m + 1, -1);
	int c = 0;
	for(int v : post_order){
		if(assigned[v] == -1){
			++c;
			assign(rev, assigned, v, c);
		}
	}
	for(int u = 1; u <= m; ++u){
		if(assigned[u] == assigned[2 * m + 1 - u]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> state(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> state[i];
	}
	vector<vector<int>> switches(n + 1);
	for(int u = 1; u <= m; ++u){
		int k;
		cin >> k;
		for(int a0 = 0; a0 < k; ++a0){
			int i;
			cin >> i;
			switches[i].push_back(u);
		}
	}
	vector<vector<int>> adj(2 * m + 1), rev(2 * m + 1);
	for(int i = 1; i <= n; ++i){
		int x = switches[i][0], y = switches[i][1];
		if(state[i]){
			adj[x].push_back(y);
			rev[y].push_back(x);
			adj[2 * m + 1 - y].push_back(2 * m + 1 - x);
			rev[2 * m + 1 - x].push_back(2 * m + 1 - y);
			adj[2 * m + 1 - x].push_back(2 * m + 1 - y);
			rev[2 * m + 1 - y].push_back(2 * m + 1 - x);
			adj[y].push_back(x);
			rev[x].push_back(y);
		}else{
			adj[2 * m + 1 - x].push_back(y);
			rev[y].push_back(2 * m + 1 - x);
			adj[2 * m + 1 - y].push_back(x);
			rev[x].push_back(2 * m + 1 - y);
			adj[x].push_back(2 * m + 1 - y);
			rev[2 * m + 1 - y].push_back(x);
			adj[y].push_back(2 * m + 1 - x);
			rev[2 * m + 1 - x].push_back(y);
		}
	}
	cout << satisfiable(adj, rev, m) << '\n';
	return 0;
}

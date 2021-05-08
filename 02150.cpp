#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void traverse(vector<int> &post_order, vector<vector<int>> &adj, vector<bool> &visited, int a){
	if(visited[a]){
		return;
	}
	visited[a] = true;
	for(int b : adj[a]){
		traverse(post_order, adj, visited, b);
	}
	post_order.push_back(a);
}

void assign(vector<vector<int>> &rev, vector<int> &assigned, vector<int> &scc, int b, int root){
	if(assigned[b] != -1){
		return;
	}
	// cout << b << ' ' << root << '\n';
	scc.push_back(b);
	assigned[b] = root;
	for(int a : rev[b]){
		assign(rev, assigned, scc, a, root);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v + 1), rev(v + 1);
	for(int i = 0; i < e; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	vector<bool> visited(v + 1);
	vector<int> post_order;
	for(int a = 1; a <= v; ++a){
		traverse(post_order, adj, visited, a);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(v + 1, -1);
	vector<vector<int>> sccs;
	for(int b : post_order){
		if(assigned[b] == -1){
			vector<int> scc;
			assign(rev, assigned, scc, b, b);
			sort(scc.begin(), scc.end());
			sccs.push_back(scc);
		}
	}
	sort(sccs.begin(), sccs.end());
	cout << sccs.size() << '\n';
	for(vector<int> &scc : sccs){
		for(int u : scc){
			cout << u << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}

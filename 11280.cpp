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

void assign(vector<vector<int>> &rev, vector<int> &assigned, int b, int root){
	if(assigned[b] != -1){
		return;
	}
	assigned[b] = root;
	for(int a : rev[b]){
		assign(rev, assigned, a, root);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(2 * n + 1), rev(2 * n + 1);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		if(a < 0){
			a += 2 * n + 1;
		}
		if(b < 0){
			b += 2 * n + 1;
		}
		adj[2 * n + 1 - a].push_back(b);
		rev[b].push_back(2 * n + 1 - a);
		adj[2 * n + 1 - b].push_back(a);
		rev[a].push_back(2 * n + 1 - b);
	}
	vector<bool> visited(2 * n + 1);
	vector<int> post_order;
	for(int a = 1; a <= 2 * n; ++a){
		traverse(post_order, adj, visited, a);
	}
	reverse(post_order.begin(), post_order.end());
	/*
	for(int x : post_order){
		cout << x << ' ';
	}
	*/
	vector<int> assigned(2 * n + 1, -1);
	int comp = 0;
	for(int b : post_order){
		if(assigned[b] == -1){
			++comp;
			assign(rev, assigned, b, comp);
		}
	}
	vector<bool> truth(n + 1);
	for(int a = 1; a <= n; ++a){
		if(assigned[a] == assigned[2 * n + 1 - a]){
			cout << 0;
			return 0;
		}else if(assigned[a] > assigned[2 * n + 1 - a]){
			truth[a] = true;
		}
	}
	cout << 1;
	return 0;
}

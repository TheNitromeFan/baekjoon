#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int find_root(vector<int> &parent, int n){
	for(int u = 1; u <= n; ++u){
		if(parent[u] == -1){
			return u;
		}
	}
	return -1;
}

void assign_depths(vector<vector<int>> &children, vector<int> &depth, int root){
	queue<int> q;
	q.push(root);
	depth[root] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : children[u]){
			q.push(v);
			depth[v] = depth[u] + 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<vector<int>> children(n + 1);
		vector<int> parent(n + 1, -1);
		for(int a1 = 0; a1 < n - 1; ++a1){
			int u, v;
			cin >> u >> v;
			children[u].push_back(v);
			parent[v] = u;
		}
		int u, v;
		cin >> u >> v;
		int root = find_root(parent, n);
		vector<int> depth(n + 1, -1);
		assign_depths(children, depth, root);
		while(depth[u] < depth[v]){
			v = parent[v];
		}
		while(depth[u] > depth[v]){
			u = parent[u];
		}
		while(u != v){
			u = parent[u];
			v = parent[v];
		}
		cout << u << '\n';
	}
	return 0;
}

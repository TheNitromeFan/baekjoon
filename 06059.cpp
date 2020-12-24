#include <iostream>
#include <vector>
#include <queue>
#define MAX 1010

using namespace std;

void traverse(vector<vector<int>> &adj, int start, vector<int> &parent, vector<vector<int>> &dir){
	queue<int> q;
	q.push(start);
	parent[start] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(parent[v] == -1){
				q.push(v);
				parent[v] = u;
				dir[u].push_back(v);
			}
		}
	}
}

int lca(vector<vector<int>> &dir, vector<int> &parent, int a, int b, int root){
	if(root == a || root == b){
		return root;
	}
	vector<int> roots;
	for(int v : dir[root]){
		int x = lca(dir, parent, a, b, v);
		if(x != 0){
			roots.push_back(x);
		}
	}
	if(roots.size() >= 2){
		return root;
	}else if(roots.size() == 1){
		return roots[0];
	}else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n + 1);
	int tree[MAX][MAX] = {};
	for(int i = 0; i < n - 1; ++i){
		int u, v, li;
		cin >> u >> v >> li;
		adj[u].push_back(v);
		adj[v].push_back(u);
		tree[u][v] = li;
		tree[v][u] = li;
	}
	vector<int> parent(n + 1, -1);
	vector<vector<int>> dir(n + 1);
	traverse(adj, 1, parent, dir);
	for(int j = 0; j < q; ++j){
		int a, b;
		cin >> a >> b;
		int c = lca(dir, parent, a, b, 1);
		int len = 0;
		for(int d = a; d != c; d = parent[d]){
			len += tree[d][parent[d]];
		}
  		for(int d = b; d != c; d = parent[d]){
			len += tree[d][parent[d]];
		}
		cout << len << '\n';
	}
	return 0;
}

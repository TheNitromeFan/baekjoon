#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void traverse(vector<vector<int>> &adj, int n, vector<int> &depth, int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			q.push(v);
			depth[v] = depth[u] + 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int root = -1;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; ++i){
		int parent;
		cin >> parent;
		if(parent == -1){
			root = i;
		}else{
			adj[parent].push_back(i);
		}
	}
	vector<int> depth(n + 1);
	traverse(adj, n, depth, root);
	for(int i = 1; i <= n; ++i){
		cout << depth[i] << '\n';
	}
	return 0;
}

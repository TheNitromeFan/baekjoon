#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void verify_dfs(vector<vector<int>> &adj, int n, int &pos, int x, vector<int> &ans){
	if(x != ans[pos]){
		return;
	}
	++pos;
	while(pos < n && find(adj[x].begin(), adj[x].end(), ans[pos]) != adj[x].end()){
		verify_dfs(adj, n, pos, ans[pos], ans);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		cin >> ans[i];
	}
	int pos = 0;
	verify_dfs(adj, n, pos, 1, ans);
	cout << (pos == n);
	return 0;
}

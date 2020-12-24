#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void verify_bfs(vector<vector<int>> &adj, int n, int &pos, int x, vector<int> &ans){
	if(ans[0] != x){
		return;
	}
	queue<int> q;
	q.push(x);
	++pos;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		while(pos < n && find(adj[u].begin(), adj[u].end(), ans[pos]) != adj[u].end()){
			q.push(ans[pos]);
			++pos;
		}
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
	verify_bfs(adj, n, pos, 1, ans);
	cout << (pos == n);
	return 0;
}

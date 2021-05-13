#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void reach(vector<vector<int>> &adj, vector<bool> &visited, int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1), rev(n + 1);
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	vector<bool> forward(n + 1), backward(n + 1);
	reach(adj, forward, 1);
	reach(rev, backward, n);
	int t;
	cin >> t;
	for(int j = 0; j < t; ++j){
		int c;
		cin >> c;
		cout << (forward[c] && backward[c] ? "Defend the CTP" : "Destroyed the CTP") << '\n';
	}
	return 0;
}

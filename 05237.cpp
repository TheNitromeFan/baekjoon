#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool connected(vector<vector<int>> &adj, int n){
	queue<int> q;
	vector<bool> visited(n);
	q.push(0);
	visited[0] = true;
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++cnt;
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return cnt == n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, k;
		cin >> n >> k;
		vector<vector<int>> adj(n);
		for(int i = 0; i < k; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << (connected(adj, n) ? "Connected." : "Not connected.") << "\n";
	}
	return 0;
}

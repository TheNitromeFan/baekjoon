#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int reachable(vector<vector<int>> &adj, int n, int start){
	queue<int> q;
	vector<bool> visited(n + 1);
	int ret = 0;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++ret;
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return ret - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		for(int i = 0; i < m; ++i){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		int ans = 0;
		for(int u = 1; u <= n; ++u){
			ans += reachable(adj, n, u);
		}
		cout << ans << '\n';
	}
	return 0;
}

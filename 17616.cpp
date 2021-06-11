#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &adj, int n, int x){
	queue<int> q;
	vector<bool> visited(n + 1);
	q.push(x);
	visited[x] = true;
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
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<int>> adj(n + 1), rev(n + 1);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	int better = bfs(rev, n, x) - 1, worse = bfs(adj, n, x) - 1;
	cout << 1 + better << ' ' << n - worse;
	return 0;
}

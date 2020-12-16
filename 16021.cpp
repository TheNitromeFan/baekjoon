#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool all_pages_reachable(vector<vector<int>> &adj, int n, int start, int &shortest_path){
	queue<int> q;
	vector<int> visited(n + 1, -1);
	int cnt = 0;
	q.push(start);
	visited[start] = 1;
	++cnt;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(adj[u].empty() && shortest_path > visited[u]){
			shortest_path = visited[u];
		}
		for(int v : adj[u]){
			if(visited[v] == -1){
				q.push(v);
				visited[v] = visited[u] + 1;
				++cnt;
			}
		}
	}
	return cnt == n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; ++i){
		int mi;
		cin >> mi;
		adj[i].resize(mi);
		for(int j = 0; j < mi; ++j){
			cin >> adj[i][j];
		}
	}
	int shortest_path = 200000;
	cout << (all_pages_reachable(adj, n, 1, shortest_path) ? 'Y' : 'N') << '\n';
	cout << shortest_path;
	return 0;
}

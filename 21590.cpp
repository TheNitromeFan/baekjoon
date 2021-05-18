#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool not_impostor(vector<vector<int>> adj, int n, int k, int start){
	vector<bool> visited(n + 1);
	queue<int> q;
	visited[start] = true;
	q.push(start);
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++cnt;
		if(cnt > k){
			return true;
		}
		for(int v : adj[u]){
			if(visited[v]){
				continue;
			}
			visited[v] = true;
			q.push(v);
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n + 1);
	for(int v = 1; v <= n; ++v){
		int s;
		cin >> s;
		for(int a0 = 0; a0 < s; ++a0){
			int u;
			cin >> u;
			adj[u].push_back(v);
		}
	}
	for(int v = 1; v <= n; ++v){
		cout << not_impostor(adj, n, k, v) << '\n';
	}
	return 0;
}

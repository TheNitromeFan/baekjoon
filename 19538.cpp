#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &adj, queue<int> &q, vector<int> &time, int n){
	vector<unsigned> neighbors(n + 1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			++neighbors[v];
			if(time[v] == -1 && 2 * neighbors[v] >= adj[v].size()){
				time[v] = time[u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int u = 1; u <= n; ++u){
		while(true){
			int v;
			cin >> v;
			if(v == 0){
				break;
			}
			adj[u].push_back(v);
		}
	}
	cin >> m;
	vector<int> time(n + 1, -1);
	queue<int> q;
	for(int i = 0; i < m; ++i){
		int v;
		cin >> v;
		time[v] = 0;
		q.push(v);
	}
	bfs(adj, q, time, n);
	for(int v = 1; v <= n; ++v){
		cout << time[v] << ' ';
	}
	return 0;
}

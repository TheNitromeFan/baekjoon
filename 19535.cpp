#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void root(vector<vector<int>> &adj, vector<int> &parent, int n){
	queue<int> q;
	vector<bool> visited(n + 1);
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				parent[v] = u;
				q.push(v);
				visited[v] = true;
			}
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
	vector<int> parent(n + 1, -1);
	root(adj, parent, n);
	long long d = 0, g = 0;
	for(int v = 1; v <= n; ++v){
		long long m = (long long)adj[v].size();
		g += m * (m - 1) / 2 * (m - 2) / 3;
		if(v == 1){
			continue;
		}
		long long p = (long long)adj[parent[v]].size();
		d += (p - 1) * (m - 1);
	}
	if(d > 3 * g){
		cout << "D";
	}else if(d < 3 * g){
		cout << "G";
	}else{
		cout << "DUDUDUNGA";
	}
	return 0;
}

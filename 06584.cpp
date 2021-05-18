#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void visit(vector<vector<int>> &adj, unordered_map<long long, bool> &visited, int u, int len, int &max){
	if(max < len){
		max = len;
	}
	for(int v : adj[u]){
		long long edge1 = u * 1000000000LL + v, edge2 = v * 1000000000LL + u;
		if(!visited[edge1] && !visited[edge2]){
			visited[edge1] = true;
			visited[edge2] = true;
			visit(adj, visited, v, len + 1, max);
			visited[edge1] = false;
			visited[edge2] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		vector<vector<int>> adj(n);
		unordered_map<long long, bool> visited;
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			visited[u * 1000000000LL + v] = false;
			visited[v * 1000000000LL + u] = false;
		}
		int max_path = 0;
		for(int v = 0; v < n; ++v){
			visit(adj, visited, v, 0, max_path);
		}
		cout << max_path << '\n';
	}
	return 0;
}

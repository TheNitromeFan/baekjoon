#include <cstdio>
#include <vector>

using std::vector;

bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int v, int cnt){
	if(cnt == 5){
		return true;
	}
	for(int u : adj[v]){
		if(!visited[u]){
			visited[u] = true;
			if(dfs(adj, visited, u, cnt + 1)){
				return true;
			}
			visited[u] = false;
		}
	}
	return false;
}

bool find_5(vector<vector<int>> &adj, int n){
	vector<bool> visited(n, false);
	for(int i = 0; i < n; ++i){
		visited[i] = true;
		if(dfs(adj, visited, i, 1)){
			return true;
		}
		visited[i] = false;
	}
	return false;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%d", find_5(adj, n));
	return 0;
}

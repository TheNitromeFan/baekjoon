#include <cstdio>

bool visited[101];

int dfs(bool a[][101], int n, int u){
	if(visited[u]){
		return 0;
	}
	visited[u] = true;
	int counter = 1;
	for(int i = 1; i <= n; ++i){
		if(a[u][i]){
			counter += dfs(a, n, i);
		}
	}
	return counter;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool adj[101][101] = {};
	for(int e = 0; e < m; ++e){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u][v] = true;
		adj[v][u] = true;
	}
	printf("%d", dfs(adj, n, 1) - 1);
	return 0;
}

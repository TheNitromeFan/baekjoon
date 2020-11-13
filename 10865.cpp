#include <cstdio>
#include <vector>

using std::vector;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> adj;
	adj.resize(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i){
		printf("%llu\n", adj[i].size());
	}
	return 0;
}

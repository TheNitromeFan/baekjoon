#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int component_cost(vector<vector<int>> &adj, vector<int> &cost, vector<bool> &visited, int vertex){
	visited[vertex] = true;
	int ret = cost[vertex];
	for(int v : adj[vertex]){
		if(!visited[v]){
			int cmp = component_cost(adj, cost, visited, v);
			if(ret > cmp){
				ret = cmp;
			}
		}
	}
	return ret;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> cost(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &cost[i]);
	}
	vector<vector<int>> adj;
	adj.resize(n + 1);
	for(int j = 0; j < m; ++j){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n + 1, false);
	int ans = 0;
	for(int u = 1; u <= n; ++u){
		if(!visited[u]){
			ans += component_cost(adj, cost, visited, u);
		}
	}
	if(ans <= k){
		printf("%d", ans);
	}else{
		printf("Oh no");
	}
	return 0;
}

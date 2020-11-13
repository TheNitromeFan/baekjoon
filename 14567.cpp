#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &adj, vector<int> &indegree, int n){
	vector<int> ret(n + 1, 1);
	queue<int> q;
	for(int v = 1; v <= n; ++v){
		if(indegree[v] == 0){
			q.push(v);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			--indegree[v];
			if(indegree[v] == 0){
				q.push(v);
				ret[v] = ret[u] + 1;
			}
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> adj;
	adj.resize(n + 1);
	vector<int> indegree(n + 1, 0);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		++indegree[v];
	}
	vector<int> ans = bfs(adj, indegree, n);
	for(int u = 1; u <= n; ++u){
		printf("%d ", ans[u]);
	}
	return 0;
}

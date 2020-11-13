#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &adj, int x, int y){
	queue<int> q;
	vector<int> relations(adj.size(), 0);
	q.push(x);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(v != x && relations[v] == 0){
				q.push(v);
				relations[v] = relations[u] + 1;
				if(v == y){
					return relations[v];
				}
			}
		}
	}
	return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	int x, y;
	scanf("%d %d", &x, &y);
	int m;
	scanf("%d", &m);
	vector<vector<int>> adj;
	adj.resize(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%d", bfs(adj, x, y));
	return 0;
}

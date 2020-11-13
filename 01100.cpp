#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void toposort(vector<int> adj[32001], int indegree[32001], int n){
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		printf("%d ", u);
		for(int v : adj[u]){
			--indegree[v];
			if(indegree[v] == 0){
				q.push(v);
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> adj[32001];
	int indegree[32001] = {};
	for(int j = 0; j < m; ++j){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		++indegree[v];
	}
	toposort(adj, indegree, n);
	return 0;
}

#include <cstdio>
#include <queue>
#define MAX (500 + 1)

int toposort(bool adj[][MAX], int indegree[MAX], int n, int ans[MAX]){
	std::queue<int> q;
	for(int u = 1; u <= n; ++u){
		if(indegree[u] == 0){
			q.push(u);
		}
	}
	int idx = 0;
	while(!q.empty()){
		if(q.size() > 1){
			return -1; // uncertain
		}
		int u = q.front();
		q.pop();
		ans[idx] = u;
		++idx;
		for(int v = 1; v <= n; ++v){
			if(adj[u][v]){
				--indegree[v];
				if(indegree[v] == 0){
					q.push(v);
				}
			}
		}
	}
	return idx == n;
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int a0 = 0; a0 < tc; ++a0){
		int n;
		scanf("%d", &n);
		int place[MAX] = {};
		bool adj[MAX][MAX] = {};
		int indegree[MAX] = {};
		for(int i = 0; i < n; ++i){
			scanf("%d", &place[i]);
			for(int j = 0; j < i; ++j){
				adj[place[j]][place[i]] = true;
				++indegree[place[i]];
			}
		}
		int m;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j){
			int u, v;
			scanf("%d %d", &u, &v);
			if(adj[u][v]){
				adj[u][v] = false;
				adj[v][u] = true;
				--indegree[v];
				++indegree[u];
			}else{
				adj[u][v] = true;
				adj[v][u] = false;
				++indegree[v];
				--indegree[u];
			}
		}
		int ans[MAX];
		int res = toposort(adj, indegree, n, ans);
		if(res == 1){
			for(int idx = 0; idx < n; ++idx){
				printf("%d ", ans[idx]);
			}
		}else if(res == 0){
			printf("IMPOSSIBLE");
		}else{
			printf("?");
		}
		printf("\n");
	}
	return 0;
}

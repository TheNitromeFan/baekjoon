#include <cstdio>
#include <queue>

using namespace std;

long long toposort(bool adj[][1001], int time[1001], int indegree[1001], int n, int w){
	queue<int> q;
	long long res[1001] = {};
	for(int i = 1; i <= n; ++i){
		if(indegree[i] == 0){
			res[i] = time[i];
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i = 1; i <= n; ++i){
			if(adj[v][i]){
				if(res[v] + time[i] > res[i]){
					res[i] = res[v] + time[i];
				}
				--indegree[i];
				if(indegree[i] == 0){
					q.push(i);
				}
			}
		}
	}
	return res[w];
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, k;
		scanf("%d %d", &n, &k);
		int time[1001] = {};
		bool adj[1001][1001] = {};
		int indegree[1001] = {};
		for(int i = 1; i <= n; ++i){
			scanf("%d", &time[i]);
		}
		for(int j = 0; j < k; ++j){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u][v] = true;
			++indegree[v];
		}
		int w;
		scanf("%d", &w);
		printf("%lld\n", toposort(adj, time, indegree, n, w));
	}
	return 0;
}

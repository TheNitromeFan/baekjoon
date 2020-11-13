#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#define MAX (32000 + 1)

using namespace std;

void topological_sort(vector<int> adj[MAX], int indegree[MAX], int n){
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i <= n; ++i){
		if(indegree[i] == 0){
			pq.push(i);
		}
	}
	while(!pq.empty()){
		int u = pq.top();
		pq.pop();
		printf("%d ", u);
		for(int v : adj[u]){
			--indegree[v];
			if(indegree[v] == 0){
				pq.push(v);
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> adj[MAX];
	int indegree[MAX] = {};
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		++indegree[v];
	}
	topological_sort(adj, indegree, n);
	return 0;
}

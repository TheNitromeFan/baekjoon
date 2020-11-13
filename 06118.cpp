#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define MAX (50000 + 1)

using namespace std;

void dijkstra(vector<vector<int>> &adj, vector<int> &dist){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(int v : adj[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> dist(n + 1, MAX);
	dist[1] = 0;
	dijkstra(adj, dist);
	/*
	for(int v = 1; v <= n; ++v){
		printf("%d ", dist[v]);
	}
	printf("\n");
	*/
	int max_dist = MAX;
	vector<int> ans;
	for(int v = 2; v <= n; ++v){
		if(dist[v] != MAX && (max_dist == MAX || max_dist < dist[v])){
			max_dist = dist[v];
			ans.clear();
			ans.push_back(v);
		}else if(dist[v] != MAX && max_dist == dist[v]){
			ans.push_back(v);
		}
	}
	printf("%d %d %llu", ans[0], max_dist, ans.size());
	return 0;
}

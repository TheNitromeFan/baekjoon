#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

struct node{
	int end;
	int val;
};

vector<node> edges[300001];

int dist[20001];

void dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	while(!pq.empty()){
		pair<int, int> tmp = pq.top();
		pq.pop();
		int v = tmp.second;
		for(unsigned k = 0; k < edges[v].size(); ++k){
			int cmp = dist[v] + edges[v][k].val;
			if(cmp < dist[edges[v][k].end]){
				dist[edges[v][k].end] = cmp;
				pq.push({-cmp, edges[v][k].end});
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int k;
	scanf("%d", &k);
	for(int e = 0; e < m; ++e){
		int u, v, val;
		scanf("%d %d %d", &u, &v, &val);
		edges[u].push_back(node{v, val});
	}
	for(int u = 1; u <= n; ++u){
		dist[u] = numeric_limits<int>::max();
	}
	dist[k] = 0;
	dijkstra(k);
	for(int u = 1; u <= n; ++u){
		if(dist[u] == numeric_limits<int>::max()){
			printf("INF\n");
		}else{
			printf("%d\n", dist[u]);
		}
	}
	return 0;
}

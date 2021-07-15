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

vector<node> edges[100001]; // edges[u]: edges emanating from u

int dist[20001]; // dist[v]: distance from start to v

void dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	bool visited[20001] = {};
	while(!pq.empty()){
		pair<int, int> tmp = pq.top();
		pq.pop();
		int v = tmp.second;
		if(visited[v]){
			continue;
		}
		visited[v] = true;
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
	for(int e = 0; e < m; ++e){
		int u, v, val;
		scanf("%d %d %d", &u, &v, &val);
		edges[u].push_back(node{v, val});
	}
	int start, end;
	scanf("%d %d", &start, &end);
	for(int u = 1; u <= n; ++u){
		dist[u] = numeric_limits<int>::max();
	}
	dist[start] = 0;
	dijkstra(start);
	printf("%d", dist[end]);
	return 0;
}

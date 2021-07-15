#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;

class Compare{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

void dijkstra(vector<pair<int, int>> edges[100001], int dist[1001], int prev[1001], int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	bool visited[1001] = {};
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first, du = p.second;
		if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, int> edge: edges[u]){
			int v = edge.first, w = edge.second;
			if(du + w < dist[v]){
				dist[v] = du + w;
				prev[v] = u;
				pq.push(make_pair(v, du + w));
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static vector<pair<int, int>> edges[100001];
	for(int a0 = 0; a0 < m; ++a0){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back(make_pair(v, w));
	}
	int start, end;
	scanf("%d %d", &start, &end);
	int dist[1001] = {}, prev[1001] = {};
	for(int u = 1; u <= n; ++u){
		dist[u] = numeric_limits<int>::max();
	}
	dist[start] = 0;
	dijkstra(edges, dist, prev, start);
	printf("%d\n", dist[end]);
	vector<int> path;
	while(end != start){
		path.push_back(end);
		end = prev[end];
	}
	path.push_back(start);
	reverse(path.begin(), path.end());
	printf("%llu\n", path.size());
	for(int v : path){
		printf("%d ", v);
	}
	return 0;
}

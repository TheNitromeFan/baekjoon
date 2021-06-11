#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAX 2100000000

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> p1, pair<int, int> p2){
			return p1.second > p2.second;
		}
};

void dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int p, int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(p + 1);
	dist[start] = 0;
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, int> p1 = pq.top();
		pq.pop();
		int u = p1.first;
		if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, int> p2 : adj[u]){
			int v = p2.first, w = p2.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, p, pb, pa1, pa2;
	cin >> c >> p >> pb >> pa1 >> pa2;
	vector<vector<pair<int, int>>> adj(p + 1);
	for(int i = 0; i < c; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back(make_pair(v, d));
		adj[v].push_back(make_pair(u, d));
	}
	vector<int> dist1(p + 1, MAX), dist2(p + 1, MAX);
	dijkstra(adj, dist1, p, pb);
	dijkstra(adj, dist2, p, pa1);
	cout << min(dist1[pa1], dist1[pa2]) + dist2[pa2];
	return 0;
}

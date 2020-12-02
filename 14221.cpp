#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define MAX 2000000000

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second < b.second;
		}
};

void dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int n, int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(n + 1);
	dist[start] = 0;
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, int> p1 : adj[u]){
			int v = p1.first, d = p1.second;
			if(dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int a0 = 0; a0 < m; ++a0){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	int p, q;
	cin >> p >> q;
	vector<int> houses(p), stores(q);
	for(int i = 0; i < p; ++i){
		cin >> houses[i];
	}
	for(int j = 0; j < q; ++j){
		cin >> stores[j];
	}
	int candidate = 0;
	int candDist = MAX;
	for(int house : houses){
		vector<int> dist(n + 1, MAX);
		dijkstra(adj, dist, n, house);
		int minDist = MAX;
		for(int store : stores){
			if(minDist > dist[store]){
				minDist = dist[store];
			}
		}
		if(candDist > minDist){
			candDist = minDist;
			candidate = house;
		}
	}
	cout << candidate;
	return 0;
}

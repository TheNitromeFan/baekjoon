#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
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
		for(pair<int, int> q : adj[u]){
			int v = q.first, w = q.second;
			if(dist[v] == -1 || dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, e, p;
	cin >> v >> e >> p;
	vector<vector<pair<int, int>>> adj(v + 1);
	for(int i = 0; i < e; ++i){
		int from, to, dist;
		cin >> from >> to >> dist;
		adj[from].push_back(make_pair(to, dist));
		adj[to].push_back(make_pair(from, dist));
	}
	vector<int> dist1(v + 1, -1), dist2(v + 1, -1);
	dijkstra(adj, dist1, v, 1);
	dijkstra(adj, dist2, v, p);
	/*
	for(int u = 1; u <= v; ++u){
		cout << dist1[u] << ' ';
	}
	cout << '\n';
	for(int u = 1; u <= v; ++u){
		cout << dist2[u] << ' ';
	}
	cout << '\n';
	*/
	cout << (dist1[v] == dist1[p] + dist2[v] ? "SAVE HIM" : "GOOD BYE");
	return 0;
}

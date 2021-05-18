#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 1000000000

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

bool dijkstra(vector<vector<pair<int, int>>> &adj, int n, int funds, int max_toll, int start, int end){
	vector<int> cost(n + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(n + 1);
	cost[start] = 0;
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(visited[u]){
			continue;
		}
		if(u == end){
			return true;
		}
		visited[u] = true;
		for(pair<int, int> q : adj[u]){
			int v = q.first, w = q.second;
			if(cost[u] + w <= funds && !visited[v] && w <= max_toll && cost[v] > cost[u] + w){
				cost[v] = cost[u] + w;
				pq.push(make_pair(v, cost[v]));
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	for(int toll = 1; toll <= 1000; ++toll){
		if(dijkstra(adj, n, c, toll, a, b)){
			cout << toll;
			return 0;
		}
	}
	cout << -1;
	return 0;
}

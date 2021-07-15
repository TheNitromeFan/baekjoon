#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAX 10000000000000000LL

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, long long> a, pair<int, long long> b){
			return a.second > b.second;
		}
};

void dijkstra(vector<vector<pair<int, long long>>> &adj, vector<long long> &dist, int n){
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, Cmp> pq;
	vector<bool> visited(n + 1);
	dist[1] = 0;
	pq.push(make_pair(1, 0));
	while(!pq.empty()){
		pair<int, long long> p = pq.top();
		pq.pop();
		int u = p.first;
		if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, long long> q : adj[u]){
			int v = q.first;
			long long d = q.second;
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
	int n;
	cin >> n;
	vector<vector<pair<int, long long>>> adj(n + 1);
	for(int i = 1; i < n; ++i){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	vector<long long> dist(n + 1, MAX);
	dijkstra(adj, dist, n);
	long long max_dist = 0;
	for(int u = 2; u <= n; ++u){
		max_dist = max(max_dist, dist[u]);
	}
	cout << max_dist << '\n';
	return 0;
}

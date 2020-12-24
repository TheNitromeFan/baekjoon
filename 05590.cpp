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

int dijkstra(vector<vector<pair<int, int>>> &adj, int n, int start, int end){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(n + 1);
	vector<int> dist(n + 1, -1);
	pq.push(make_pair(start, 0));
	visited[start] = true;
	dist[start] = 0;
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == end){
			return dist[end];
		}
		for(pair<int, int> edge : adj[u]){
			int v = edge.first, d = edge.second;
			if(!visited[v] || dist[v] > dist[u] + d){
				pq.push(make_pair(v, dist[u] + d));
				visited[v] = true;
				dist[v] = dist[u] + d;
			}
		}
	}
	return dist[end];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int a0 = 0; a0 < k; ++a0){
		int q;
		cin >> q;
		if(q){
			int c, d, e;
			cin >> c >> d >> e;
			adj[c].push_back(make_pair(d, e));
			adj[d].push_back(make_pair(c, e));
		}else{
			int a, b;
			cin >> a >> b;
			cout << dijkstra(adj, n, a, b) << '\n';
		}
	}
	return 0;
}

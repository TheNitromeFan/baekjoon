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

void dijkstra(vector<vector<pair<int, int>>> &adj, int n, int start, int end, vector<int> &prev){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<int> dist(n + 1, -1);
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == end){
			return;
		}
		for(pair<int, int> edge : adj[u]){
			int v = edge.first, d = edge.second;
			if(dist[v] == -1 || dist[v] > dist[u] + d){
				pq.push(make_pair(v, dist[u] + d));
				dist[v] = dist[u] + d;
				prev[v] = u;
			}
		}
	}
}

int dist(vector<vector<pair<int, int>>> &adj, vector<int> &prev, int start, int end){
	int sum = 0, max = 0;
	while(end != start){
		int u = prev[end];
		for(pair<int, int> edge : adj[u]){
			if(edge.first == end){
				sum += edge.second;
				if(max < edge.second){
					max = edge.second;
				}
			}
		}
		end = u;
	}
	return sum - max;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back(make_pair(v, d));
		adj[v].push_back(make_pair(u, d));
	}
	vector<int> prev(n + 1);
	dijkstra(adj, n, a, b, prev);
	cout << dist(adj, prev, a, b);
	return 0;
}

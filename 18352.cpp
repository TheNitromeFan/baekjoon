#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Compare{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

void dijkstra(vector<vector<int>> &adj, vector<int> &dist, int n, int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	vector<bool> visited(n + 1);
	pq.push(make_pair(start, 0));
	dist[start] = 0;
	visited[start] = true;
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		for(int v : adj[u]){
			if(visited[v]){
				continue;
			}
			if(dist[v] == -1 || dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				pq.push(make_pair(v, dist[v]));
				visited[v] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<int> dist(n + 1, -1);
	dijkstra(adj, dist, n, x);
	vector<int> ans;
	for(int v = 1; v <= n; ++v){
		// cout << dist[v];
		if(dist[v] == k){
			ans.push_back(v);
		}
	}
	if(!ans.empty()){
		for(int v : ans){
			cout << v << '\n';
		}
	}else{
		cout << "-1";
	}
	return 0;
}

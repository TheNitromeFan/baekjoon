#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define MAX 1001
#define MAX_VAL 100000000

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second < b.second;
		}
};

void dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int n, int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	pq.push(make_pair(start, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		for(pair<int, int> q : adj[u]){
			int v = q.first, d = q.second;
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
	int n, m, x;
	cin >> n >> m >> x;
	int adj[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			adj[i][j] = MAX_VAL;
		}
	}
	for(int a0 = 0; a0 < m; ++a0){
		int a, b, val;
		cin >> a >> b >> val;
		adj[a][b] = min(adj[a][b], val);
		adj[b][a] = min(adj[b][a], val);
	}
	vector<vector<pair<int, int>>> adj1(n + 1);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(adj[i][j] != MAX_VAL){
				adj1[i].push_back(make_pair(j, adj[i][j]));
			}
		}
	}
	vector<int> dist(n + 1, MAX);
	dist[x] = 0;
	dijkstra(adj1, dist, n, x);
	int time = 0;
	for(int i = 1; i <= n; ++i){
		time = max(time, 2 * dist[i]);
	}
	cout << time;
	return 0;
}

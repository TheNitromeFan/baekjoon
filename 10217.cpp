#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX 1000000000

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b);
		}
};

void dijkstra(vector<vector<tuple<int, int, int>>> &adj, vector<vector<int>> &dist,
		int n, int m, int start){
	vector<vector<bool>> visited(n + 1);
	for(int v = 1; v <= n; ++v){
		visited[v].resize(m + 1);
	}
	dist.resize(n + 1);
	for(int v = 1; v <= n; ++v){
		dist[v].resize(m + 1);
		fill(dist[v].begin(), dist[v].end(), MAX);
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	pq.push(make_tuple(start, 0, 0));
	visited[start][0] = true;
	dist[start][0] = 0;
	while(!pq.empty()){
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int u = get<0>(t), c = get<1>(t), d = get<2>(t);
		if(d > dist[u][c]){
			continue;
		}
		for(tuple<int, int, int> e : adj[u]){
			int v = get<0>(e), c1 = get<1>(e), d1 = get<2>(e);
			int money = c + c1, distance = d + d1;
			if(money > m){
				continue;
			}
			if(!visited[v][money] || distance < dist[v][money]){
				pq.push(make_tuple(v, money, distance));
				visited[v][money] = true;
				dist[v][money] = distance;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<tuple<int, int, int>>> adj(n + 1);
		for(int i = 0; i < k; ++i){
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u].push_back(make_tuple(v, c, d));
		}
		vector<vector<int>> dist;
		dijkstra(adj, dist, n, m, 1);
		int ans = MAX;
		for(int c = 1; c <= m; ++c){
			if(dist[n][c] < ans){
				ans = dist[n][c];
			}
		}
		if(ans < MAX){
			cout << ans << "\n";
		}else{
			cout << "Poor KCM\n";
		}
	}
	return 0;
}

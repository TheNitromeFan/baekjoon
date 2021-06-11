#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <iomanip>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, double> p1, pair<int, double> p2){
			return p1.second < p2.second;
		}
};

double dijkstra(vector<vector<pair<int, double>>> &adj, int n){
	vector<double> dist(n + 1, -1);
	priority_queue<pair<int, double>, vector<pair<int, double>>, Cmp> pq;
	vector<bool> visited(n + 1);
	dist[1] = 1;
	pq.push(make_pair(1, 1));
	while(!pq.empty()){
		pair<int, double> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == n){
			break;
		}
		if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, double> q : adj[u]){
			int v = q.first;
			double w = q.second;
			if(dist[v] < dist[u] * w){
				dist[v] = dist[u] * w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
	return dist[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m;
		cin >> n;
		if(n == 0){
			break;
		}
		cin >> m;
		vector<vector<pair<int, double>>> adj(n + 1);
		for(int i = 0; i < m; ++i){
			int a, b, p;
			cin >> a >> b >> p;
			adj[a].push_back(make_pair(b, p / 100.0));
			adj[b].push_back(make_pair(a, p / 100.0));
		}
		cout << fixed << setprecision(9) << dijkstra(adj, n) * 100 << " percent\n";
	}
	return 0;
}

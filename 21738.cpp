#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int leaf_dist(vector<vector<int>> &adj, int n, int p, int s){
	queue<int> q;
	vector<int> dist(n + 1, -1);
	q.push(p);
	dist[p] = 0;
	int support_count = 0;
	int ret = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u <= s){
			++support_count;
			ret += dist[u];
			if(support_count == 2){
				break;
			}
		}
		for(int v : adj[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s, p;
	cin >> n >> s >> p;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << n - leaf_dist(adj, n, p, s);
	return 0;
}

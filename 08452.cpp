#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAX 1000000000

using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &dist, int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector<pair<int, int>> edges(m + 1);
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		edges[i] = make_pair(u, v);
	}
	vector<pair<char, int>> queries(q);
	for(int j = 0; j < q; ++j){
		char c;
		int p;
		cin >> c >> p;
		queries[j] = make_pair(c, p);
	}
	vector<bool> edge_removed(m + 1);
	for(int j = 0; j < q; ++j){
		if(queries[j].first == 'U'){
			edge_removed[queries[j].second] = true;
		}
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= m; ++i){
		if(!edge_removed[i]){
			pair<int, int> edge = edges[i];
			int u = edge.first, v = edge.second;
			adj[u].push_back(v);
		}
	}
	vector<int> dist(n + 1, MAX);
	dist[1] = 0;
	bfs(adj, dist, 1);
	reverse(queries.begin(), queries.end());
	vector<int> ans;
	for(pair<char, int> query : queries){
		char c = query.first;
		int p = query.second;
		if(c == 'U'){
			pair<int, int> edge = edges[p];
			int u = edge.first, v = edge.second;
			adj[u].push_back(v);
			bfs(adj, dist, u);
		}else{
			ans.push_back(dist[p] == MAX ? -1 : dist[p]);
		}
	}
	reverse(ans.begin(), ans.end());
	for(int x : ans){
		cout << x << '\n';
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vertices(n);
	for(int i = 0; i < n; ++i){
		vertices[i] = i;
	}
	sort(vertices.begin(), vertices.end(), [&adj](int i, int j){
		return adj[i].size() < adj[j].size();
	});
	vector<int> max_length(n); // max_length[i]: maximum length of path ending at vertex i
	int ans = 0;
	for(int u : vertices){
		max_length[u] = 1;
		for(int v : adj[u]){
			if(adj[u].size() > adj[v].size() && max_length[u] < max_length[v] + 1){
				max_length[u] = max_length[v] + 1;
			}
		}
		if(ans < max_length[u]){
			ans = max_length[u];
		}
	}
	cout << ans;
	return 0;
}

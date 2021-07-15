#include <iostream>
#include <vector>

using namespace std;

bool bipartite_matching(vector<vector<int>> &adj, vector<int> &matched, vector<bool> &visited, int u){
	for(int v : adj[u]){
		if(!visited[v]){
			visited[v] = true;
			if(matched[v] == -1 || bipartite_matching(adj, matched, visited, matched[v])){
				matched[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> shirt(n), collar(m);
	for(int i = 0; i < n; ++i){
		cin >> shirt[i];
	}
	for(int j = 0; j < m; ++j){
		cin >> collar[j];
	}
	vector<vector<int>> adj(n + m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if((2 * collar[j] >= shirt[i] && 4 * collar[j] <= 3 * shirt[i]) || (collar[j] >= shirt[i] && 4 * collar[j] <= 5 * shirt[i])){
				adj[i].push_back(n + j);
				adj[n + j].push_back(i);
			}
		}
	}
	vector<int> matched(n + m, -1);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		vector<bool> visited(n + m);
		if(bipartite_matching(adj, matched, visited, i)){
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}

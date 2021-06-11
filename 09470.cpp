#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int river_order(vector<vector<int>> &adj, vector<int> &indegree, int m){
	queue<int> q;
	vector<pair<int, int>> order(m + 1);
	for(int u = 1; u <= m; ++u){
		if(indegree[u] == 0){
			q.push(u);
			order[u] = make_pair(1, 0);
		}
	}
	int ret = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ret = order[u].first;
		// cout << u << ' ' << order[u].first << ' ' << order[u].second << '\n';
		for(int v : adj[u]){
			if(order[v].first < order[u].first){
				order[v] = make_pair(order[u].first, 1);
			}else if(order[v].first == order[u].first){
				++order[v].second;
			}
			--indegree[v];
			if(indegree[v] == 0){
				q.push(v);
				if(order[v].second >= 2){
					order[v] = make_pair(order[v].first + 1, 0);
				}
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 0; a0 < k; ++a0){
		int t, m, p;
		cin >> t >> m >> p;
		vector<vector<int>> adj(m + 1);
		vector<int> indegree(m + 1);
		for(int a1 = 0; a1 < p; ++a1){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			++indegree[v];
		}
		cout << t << ' ' << river_order(adj, indegree, m) << '\n';
	}
	return 0;
}

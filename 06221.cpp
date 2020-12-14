#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void max_depth(vector<vector<int>> &adj, int n, int x, int &cnt){
	vector<int> dist(n, -1);
	queue<int> q;
	q.push(x);
	dist[x] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(cnt < dist[u]){
			cnt = dist[u];
		}
		for(int v : adj[u]){
			if(dist[v] == -1 || dist[v] < dist[u] + 1){
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(v[i].first < v[j].first && v[i].second < v[j].second){
				adj[j].push_back(i);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		max_depth(adj, n, i, ans);
	}
	cout << ans;
	return 0;
}

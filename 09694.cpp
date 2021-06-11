#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAX 1000000000

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

bool dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &prev, int m){
	vector<int> dist(m, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	vector<bool> visited(m);
	dist[0] = 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int u = p.first;
		if(u == m - 1){
			return true;
		}
		if(visited[u]){
			continue;
		}
		visited[u] = true;
		for(pair<int, int> q : adj[u]){
			int v = q.first, d = q.second;
			if(dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				pq.push(make_pair(v, dist[v]));
				prev[v] = u;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, int>>> adj(m);
		for(int i = 0; i < n; ++i){
			int x, y, z;
			cin >> x >> y >> z;
			adj[x].push_back(make_pair(y, z));
			adj[y].push_back(make_pair(x, z));
		}
		vector<int> prev(m, -1);
		cout << "Case #" << a0 << ':';
		if(dijkstra(adj, prev, m)){
			vector<int> ans = {m - 1};
			while(ans.back() != 0){
				ans.push_back(prev[ans.back()]);
			}
			reverse(ans.begin(), ans.end());
			for(int x : ans){
				cout << ' ' << x;
			}
		}else{
			cout << ' ' << -1;
		}
		cout << '\n';
	}
	return 0;
}

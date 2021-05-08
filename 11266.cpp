#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &tin, vector<int> &low,
			int v, int p, int &timer, unordered_set<int> &cut_points){
	visited[v] = true;
	tin[v] = timer;
	low[v] = timer;
	++timer;
	// cout << v << ' ';
	int children = 0;
	for(int to : adj[v]){
		if(to == p){
			continue;
		}
		if(visited[to]){
			low[v] = min(low[v], tin[to]);
		}else{
			dfs(adj, visited, tin, low, to, v, timer, cut_points);
			low[v] = min(low[v], low[to]);
			if(low[to] >= tin[v] && p != -1){
				cut_points.insert(v);
			}
			++children;
		}
	}
	if(p == -1 && children > 1){
		cut_points.insert(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v + 1);
	for(int i = 0; i < e; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited(v + 1);
	vector<int> tin(v + 1, -1), low(v + 1, -1);
	int timer = 0;
	unordered_set<int> cut_points;
	for(int a = 1; a <= v; ++a){
		if(!visited[a]){
			dfs(adj, visited, tin, low, a, -1, timer, cut_points);
		}
	}
	vector<int> ans;
	for(int x : cut_points){
		ans.push_back(x);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int c : ans){
		cout << c << ' ';
	}
	return 0;
}

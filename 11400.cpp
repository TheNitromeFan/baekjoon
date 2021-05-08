#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>

using namespace std;

struct pair_hash{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &pair) const{
        size_t h1 =std::hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &tin, vector<int> &low,
			 int v, int p, int &timer, unordered_set<pair<int, int>, pair_hash> &cut_edges){
	visited[v] = true;
	tin[v] = timer;
	low[v] = timer;
	++timer;
	for(int to : adj[v]){
		if(to == p){
			continue;
		}
		if(visited[to]){
			low[v] = min(low[v], tin[to]);
		}else{
			dfs(adj, visited, tin, low, to, v, timer, cut_edges);
			low[v] = min(low[v], low[to]);
			if(low[to] > tin[v]){
				cut_edges.insert(make_pair(min(to, v), max(to, v)));
			}
		}
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
	unordered_set<pair<int, int>, pair_hash> cut_edges;
	for(int a = 1; a <= v; ++a){
		if(!visited[a]){
			dfs(adj, visited, tin, low, a, -1, timer, cut_edges);
		}
	}
	vector<pair<int, int>> ans;
	for(pair<int, int> p : cut_edges){
		ans.push_back(p);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(pair<int, int> p : ans){
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}

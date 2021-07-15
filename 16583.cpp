#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}
	parent[x] = find_parent(parent, parent[x]);
	return parent[x];
}

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	parent[py] = px;
}

int dfs(vector<vector<int>> &adj, vector<tuple<int, int, int>> &ans, vector<bool> &visited, int u){
	visited[u] = true;
	int t = -1;
	for(int v : adj[u]){
		if(visited[v]){
			continue;
		}
		int w = dfs(adj, ans, visited, v);
		if(w == -1 && t == -1){
			t = v;
		}else if(w == -1){
			ans.push_back(make_tuple(t, u, v));
			t = -1;
		}else{
			ans.push_back(make_tuple(u, v, w));
		}
	}
	return t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + m);
	vector<int> original(n + m);
	vector<int> parent(n);
	for(int u = 0; u < n; ++u){
		parent[u] = u;
		original[u] = u;
	}
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		if(find_parent(parent, u) == find_parent(parent, v)){
			original[n] = v;
			v = n;
			++n;
		}else{
			unite(parent, u, v);
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n);
	vector<tuple<int, int, int>> ans;
	for(int u = 0; u < n; ++u){
		if(!visited[u]){
			dfs(adj, ans, visited, u);
		}
	}
	cout << ans.size() << '\n';
	for(tuple<int, int, int> t : ans){
		int u = get<0>(t), v = get<1>(t), w = get<2>(t);
		cout << original[u] + 1 << ' ' << original[v] + 1 << ' ' << original[w] + 1 << '\n';
	}
	return 0;
}

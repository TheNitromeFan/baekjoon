#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long dfs(vector<vector<int>> &adj, vector<bool> &visited, string &a, int cur, int prev){
	long long ret = 0;
	visited[cur] = true;
	for(int v : adj[cur]){
		if(v == prev){
			continue;
		}
		if(a[v] == '0'){
			ret += dfs(adj, visited, a, v, cur);
		}else{
			++ret;
		}
	}
	return ret;
}

int neighbors(vector<vector<int>> &adj, string &a, int u){
	int ret = 0;
	for(int v : adj[u]){
		if(a[v] == '1'){
			++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string a;
	cin >> a;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n);
	long long ans = 0;
	for(int u = 0; u < n; ++u){
		if(a[u] == '0' && !visited[u]){
			long long p = dfs(adj, visited, a, u, -1);
			ans += p * (p - 1);
		}else if(a[u] == '1'){
			ans += neighbors(adj, a, u);
 		}
	}
	cout << ans << '\n';
	return 0;
}

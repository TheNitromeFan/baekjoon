#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool visit(vector<vector<pair<int, char>>> &adj, vector<int> &visited, int n, int x){
	// cout << x << '\n';
	for(pair<int, char> p : adj[x]){
		int v = p.first;
		char t = p.second;
		// cout << v << '\n';
		if((visited[v] == visited[x] && t == 'D') || (visited[v] == 3 - visited[x] && t == 'S')){
			return false;
		}else if(visited[v] > 0){
			continue;
		}
		if(t == 'S'){
			visited[v] = visited[x];
		}else{
			visited[v] = 3 - visited[x];
		}
		if(!visit(adj, visited, n, v)){
			return false;
		}
	}
	return true;
}

int components(vector<vector<pair<int, char>>> &adj, int n){
	vector<int> visited(n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(visited[i] == 0){
			++cnt;
			visited[i] = 1;
			if(!visit(adj, visited, n, i)){
				return -1;
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, char>>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		char type;
		int u, v;
		cin >> type >> u >> v;
		adj[u].push_back(make_pair(v, type));
		adj[v].push_back(make_pair(u, type));
	}
	int k = components(adj, n);
	if(k != -1){
		cout << "1" << string(k, '0');
	}else{
		cout << "0";
	}
	return 0;
}

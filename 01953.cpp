#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &visited, int u, int c){
	visited[u] = c;
	for(int v : adj[u]){
		if(visited[v] == -1){
			dfs(adj, visited, v, 1 - c);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int u = 1; u <= n; ++u){
		int x;
		cin >> x;
		for(int j = 0; j < x; ++j){
			int v;
			cin >> v;
			adj[u].push_back(v);
		}
	}
	vector<int> visited(n + 1, -1);
	for(int u = 1; u <= n; ++u){
		if(visited[u] == -1){
			dfs(adj, visited, u, 0);
		}
	}
	vector<int> blue, white;
	for(int u = 1; u <= n; ++u){
		if(visited[u]){
			white.push_back(u);
		}else{
			blue.push_back(u);
		}
	}
	if(white.empty()){
		white.push_back(blue.back());
		blue.pop_back();
	}
	cout << blue.size() << '\n';
	for(int x : blue){
		cout << x << ' ';
	}
	cout << '\n';
	cout << white.size() << '\n';
	for(int y : white){
		cout << y << ' ';
	}
	cout << '\n';
	return 0;
}

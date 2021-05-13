#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool can_color(vector<vector<int>> &adj, vector<int> &colored, int v, int color){
	for(int u : adj[v]){
		if(colored[u] == color){
			return false;
		}
	}
	return true;
}

bool graph_color(vector<vector<int>> &adj, vector<int> &colored, int n, int colors, int cur){
	if(cur == n + 1){
		return true;
	}
	for(int c = 1; c <= colors; ++c){
		if(can_color(adj, colored, cur, c)){
			colored[cur] = c;
			if(graph_color(adj, colored, n, colors, cur + 1)){
				return true;
			}
			colored[cur] = 0;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int colors = 1;
	vector<int> colored(n + 1);
	while(!graph_color(adj, colored, n, colors, 1)){
		cout << colors << '\n';
		++colors;
	}
	vector<vector<int>> ans(colors + 1);
	for(int v = 1; v <= n; ++v){
		ans[colored[v]].push_back(v);
	}
	ofstream file("10963.txt");
	file << colors << '\n';
	for(int color = 1; color <= colors; ++color){
		for(int v : ans[color]){
			file << v << ' ';
		}
		file << '\n';
	}
	return 0;
}

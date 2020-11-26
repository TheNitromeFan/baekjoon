#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		if(u < v){
			adj[v].push_back(u);
		}else{
			adj[u].push_back(v);
		}
	}
	vector<int> colors(n + 1);
	for(int i = 1; i <= n; ++i){
		colors[i] = 1;
		while(true){
			bool flag = true;
			for(int v : adj[i]){
				if(colors[v] == colors[i]){
					flag = false;
					break;
				}
			}
			if(flag){
				break;
			}
			++colors[i];
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << colors[i];
	}
	return 0;
}

#include <iostream>
#include <vector>
#define MAX 4001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	bool friends[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		friends[u][v] = true;
		friends[v][u] = true;
	}
	int ans = -1;
	for(int u = 1; u <= n; ++u){
		for(unsigned i = 0; i < adj[u].size(); ++i){
			int v = adj[u][i];
			for(unsigned j = 0; j < i; ++j){
				int w = adj[u][j];
				if(friends[v][w]){
					int cmp = (int)(adj[u].size() + adj[v].size() + adj[w].size()) - 6;
					if(ans == -1 || ans > cmp){
						ans = cmp;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

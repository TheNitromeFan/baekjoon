#include <cstdio>
#include <vector>
#define MAXM 81

using namespace std;

bool bipartite_match(vector<vector<int>> &adj, vector<int> &matched, vector<bool> &visited, int u){
	for(int v : adj[u]){
		if(!visited[v]){
			visited[v] = true;
			if(matched[v] == -1 || bipartite_match(adj, matched, visited, matched[v])){
				matched[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int c;
	scanf("%d", &c);
	for(int a0 = 0; a0 < c; ++a0){
		int m, n;
		scanf("%d %d", &m, &n);
		char map[MAXM][MAXM];
		for(int i = 0; i < m; ++i){
			scanf("%s", map[i]);
		}
		int dx[3] = {-1, -1, 0};
		int dy[3] = {-1, 1, -1};
		vector<vector<int>> adj(n * m);
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				for(int k = 0; k < 3; ++k){
					int ni = i + dx[k];
					int nj = j + dy[k];
					if(ni >= 0 && ni < m && nj >= 0 && nj < n && map[i][j] == '.' && map[ni][nj] == '.'){
						adj[n * i + j].push_back(n * ni + nj);
						adj[n * ni + nj].push_back(n * i + j);
					}
				}
			}
		}
		vector<int> matched(n * m, -1);
		int total = n * m;
		int matchable = 0;
		for(int u = 0; u < n * m; ++u){
			if(map[u / n][u % n] != '.'){
				--total;
				continue;
			}
			vector<bool> visited(n * m);
			if(bipartite_match(adj, matched, visited, u)){
				++matchable;
			}
		}
		printf("%d\n", total - matchable / 2);
	}
	return 0;
}

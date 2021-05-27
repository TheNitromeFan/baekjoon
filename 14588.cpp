#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#define MAX 301

using namespace std;

int intersect(pair<int, int> p1, pair<int, int> p2){
	return !(p1.second < p2.first) && !(p2.second < p1.first);
}

void floyd_warshall(int adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][k] != -1 && adj[k][j] != -1 && (adj[i][j] == -1 || adj[i][j] > adj[i][k] + adj[k][j])){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> lines(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> lines[i].first >> lines[i].second;
	}
	int adj[MAX][MAX];
	memset(adj, -1, sizeof(adj));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == j){
				adj[i][j] = 0;
			}else if(intersect(lines[i], lines[j])){
				adj[i][j] = 1;
			}
		}
	}
	floyd_warshall(adj, n);
	int q;
	cin >> q;
	for(int a0 = 0; a0 < q; ++a0){
		int u, v;
		cin >> u >> v;
		cout << adj[u][v] << '\n';
	}
	return 0;
}

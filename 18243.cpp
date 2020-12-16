#include <iostream>
#include <cstring>
#define MAX 101

using namespace std;

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

bool small_world(int adj[][MAX], int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(adj[i][j] == -1 || adj[i][j] > 6){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int adj[MAX][MAX];
	memset(adj, -1, sizeof(adj));
	for(int u = 1; u <= n; ++u){
		adj[u][u] = 0;
	}
	for(int i = 0; i < k; ++i){
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	floyd_warshall(adj, n);
	cout << (small_world(adj, n) ? "Small World!" : "Big World!");
	return 0;
}

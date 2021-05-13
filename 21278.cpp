#include <iostream>
#include <cstring>
#include <algorithm>
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

int sum_of_distances(int adj[][MAX], int n, int a, int b){
	int ret = 0;
	for(int i = 1; i <= n; ++i){
		ret += min(adj[i][a], adj[i][b]);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int adj[MAX][MAX] = {};
	memset(adj, -1, sizeof(adj));
	for(int u = 1; u <= n; ++u){
		adj[u][u] = 0;
	}
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	floyd_warshall(adj, n);
	int small = 1, big = 2;
	int min_distance = sum_of_distances(adj, n, 1, 2);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j){
			int cmp = sum_of_distances(adj, n, j, i);
			if(cmp < min_distance){
				small = j;
				big = i;
				min_distance = cmp;
			}
		}
	}
	cout << small << ' ' << big << ' ' << 2 * min_distance;
	return 0;
}

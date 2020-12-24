#include <iostream>
#define MAX 101

using namespace std;

void floyd_warshall(bool adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][k] && adj[k][j]){
					adj[i][j] = true;
				}
			}
		}
	}
}

bool all_reachable(bool adj[][MAX], int n, int v){
	for(int u = 1; u <= n; ++u){
		if(!adj[u][v]){
			return false;
		}
	}
	return true;
}

int walkway(bool adj[][MAX], int n){
	for(int i = 1; i <= n; ++i){
		if(all_reachable(adj, n, i)){
			return i;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool adj[MAX][MAX] = {};
	for(int u = 1; u <= n; ++u){
		adj[u][u] = true;
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u][v] = true;
	}
	floyd_warshall(adj, n);
	cout << walkway(adj, n);
	return 0;
}

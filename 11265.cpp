#include <iostream>
#define MAX 510

using namespace std;

void floyd_warshall(int adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][j] > adj[i][k] + adj[k][j]){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int adj[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> adj[i][j];
		}
	}
	floyd_warshall(adj, n);
	for(int a0 = 0; a0 < m; ++a0){
		int a, b, c;
		cin >> a >> b >> c;
		if(adj[a][b] <= c){
			cout << "Enjoy other party\n";
		}else{
			cout << "Stay here\n";
		}
	}
	return 0;
}

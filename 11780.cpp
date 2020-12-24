#include <iostream>
#include <vector>
#define MAX 105

using namespace std;

void floyd_warshall(int adj[][MAX], int dp[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(i != j && adj[i][k] != 0 && adj[k][j] != 0 && (adj[i][j] == 0 || adj[i][j] > adj[i][k] + adj[k][j])){
					adj[i][j] = adj[i][k] + adj[k][j];
					dp[i][j] = k;
				}
			}
		}
	}
}

void find_path(int dp[][MAX], int start, int end, vector<int> &v){
	if(dp[start][end] == 0){
		v.push_back(start);
		v.push_back(end);
		return;
	}
	find_path(dp, start, dp[start][end], v);
	v.pop_back();
	find_path(dp, dp[start][end], end, v);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int adj[MAX][MAX] = {};
	int dp[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		if(adj[a][b] == 0 || adj[a][b] > c){
			adj[a][b] = c;
		}
	}
	floyd_warshall(adj, dp, n);
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= n; ++v){
			cout << adj[u][v] << ' ';
		}
		cout << '\n';
	}
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= n; ++v){
			if(adj[u][v] == 0){
				cout << 0 << '\n';
				continue;
			}
			vector<int> vec;
			find_path(dp, u, v, vec);
			cout << vec.size();
			for(int x : vec){
				cout << ' ' << x;
			}
			cout << '\n';
		}
	}
	return 0;
}

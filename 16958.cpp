#include <iostream>
#include <utility>
#include <cstdlib>
#define MAXN 1001
#define MAX 1000000000

using namespace std;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

void floyd_warshall(int adj[][MAXN], int n){
	for(int k = 1; k <= n; ++k){
		for(int u = 1; u <= n; ++u){
			for(int v = 1; v <= n; ++v){
				adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	int adj[MAXN][MAXN];
	for(int u = 1; u < MAXN; ++u){
		for(int v = 1; v <= MAXN; ++v){
			adj[u][v] = MAX;
		}
	}
	pair<int, int> p[MAXN];
	int tele[MAXN] = {};
	for(int u = 1; u <= n; ++u){
		int s, x, y;
		cin >> s >> x >> y;
		tele[u] = s;
		p[u] = make_pair(x, y);
	}
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= n; ++v){
			adj[u][v] = dist(p[u].first, p[u].second, p[v].first, p[v].second);
			if(tele[u] && tele[v]){
				adj[u][v] = min(adj[u][v], t);
			}
		}
	}
	floyd_warshall(adj, n);
	int m;
	cin >> m;
	for(int j = 0; j < m; ++j){
		int a, b;
		cin >> a >> b;
		cout << adj[a][b] << '\n';
	}
	return 0;
}

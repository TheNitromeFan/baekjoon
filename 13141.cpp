#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#define MAX 201
#define MAXVAL 1000000000

using namespace std;

void floyd_warshall(int adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

double burn(int adj[][MAX], int s, int a, int b, int c){
	int t1 = adj[s][a];
	int t2 = adj[s][b];
	if(t1 > t2){
		swap(t1, t2);
	}
	if(t2 - t1 >= c){
		return t1 + c;
	}else{
		return (t1 + t2 + c) / 2.0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges(m);
	int adj[MAX][MAX];
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= n; ++v){
			adj[u][v] = (u == v ? 0 : MAXVAL);
		}
	}
	for(int i = 0; i < m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = make_tuple(a, b, c);
		adj[a][b] = min(adj[a][b], c);
		adj[b][a] = min(adj[b][a], c);
	}
	floyd_warshall(adj, n);
	double ans = MAXVAL;
	for(int u = 1; u <= n; ++u){
		double cmp = 0;
		for(tuple<int, int, int> edge : edges){
			int a = get<0>(edge), b = get<1>(edge), c = get<2>(edge);
			cmp = max(cmp, burn(adj, u, a, b, c));
		}
		ans = min(ans, cmp);
	}
	cout << fixed << setprecision(1) << ans;
	return 0;
}

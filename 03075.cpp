#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define MAXVAL 1000000000000000000LL

using namespace std;

void floyd_warshall(long long adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

long long sum_of_dists(long long adj[][MAX], vector<int> &v, int dest){
	long long ret = 0;
	for(int x : v){
		if(adj[x][dest] == MAXVAL){
			return MAXVAL;
		}
		ret += adj[x][dest] * adj[x][dest];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, p, q;
		cin >> n >> p >> q;
		vector<int> vec(n);
		for(int idx = 0; idx < n; ++idx){
			cin >> vec[idx];
		}
		long long adj[MAX][MAX];
		for(int i = 1; i <= p; ++i){
			for(int j = 1; j <= p; ++j){
				if(i == j){
					adj[i][j] = 0;
				}else{
					adj[i][j] = MAXVAL;
				}
			}
		}
		for(int a0 = 0; a0 < q; ++a0){
			int u, v;
			long long d;
			cin >> u >> v >> d;
			adj[u][v] = min(adj[u][v], d);
			adj[v][u] = min(adj[v][u], d);
		}
		floyd_warshall(adj, p);
		int meet_point = -1;
		long long min_dist = MAXVAL;
		for(int u = 1; u <= p; ++u){
			long long cmp = sum_of_dists(adj, vec, u);
			if(cmp < min_dist){
				meet_point = u;
				min_dist = cmp;
			}
		}
		cout << meet_point << ' ' << min_dist << '\n';
	}
	return 0;
}

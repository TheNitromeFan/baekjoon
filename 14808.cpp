#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAX 101

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, q;
		cin >> n >> q;
		int e[MAX], s[MAX];
		for(int i = 1; i <= n; ++i){
			cin >> e[i] >> s[i];
		}
		long long adj[MAX][MAX];
		for(int y = 1; y <= n; ++y){
			for(int x = 1; x <= n; ++x){
				cin >> adj[y][x];
			}
		}
		for(int z = 1; z <= n; ++z){
			for(int y = 1; y <= n; ++y){
				for(int x = 1; x <= n; ++x){
					if(adj[y][z] != -1 && adj[z][x] != -1 && (adj[y][x] == -1 || adj[y][x] > adj[y][z] + adj[z][x])){
						adj[y][x] = adj[y][z] + adj[z][x];
					}
				}
			}
		}
		double time[MAX][MAX];
		for(int y = 1; y <= n; ++y){
			for(int x = 1; x <= n; ++x){
				if(adj[y][x] > e[y]){
					time[y][x] = -1;
				}else{
					time[y][x] = adj[y][x] / (double)s[y];
				}
			}
		}
		for(int z = 1; z <= n; ++z){
			for(int y = 1; y <= n; ++y){
				for(int x = 1; x <= n; ++x){
					if(time[y][z] > 0 && time[z][x] > 0 && (time[y][x] <= 0 || time[y][x] > time[y][z] + time[z][x])){
						time[y][x] = time[y][z] + time[z][x];
					}
			#include <cstdio>
#include <cfloat>

#define MAXN 100
#define INF 0x3f3f3f3f

typedef long double ld;

int e[MAXN], s[MAXN], d[MAXN][MAXN], u[MAXN], v[MAXN];

ld timeTo[MAXN][MAXN];

template<typename T> void floyd(int n, T dist[MAXN][MAXN]) {
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, q; scanf("%d %d\n", &n, &q);
    for(int i = 0; i < n; i++) {
      scanf("%d %d\n", &e[i], &s[i]);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        scanf("%d", &d[i][j]);
        if(d[i][j] == -1) d[i][j] = INF;
      }
      d[i][i] = 0;
    }
    for(int i = 0; i < q; i++) {
      scanf("%d %d\n", &u[i], &v[i]);
    }

    floyd(n, d);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        timeTo[i][j] = e[i] >= d[i][j] ? d[i][j] / (ld) s[i] : LDBL_MAX / 2;
      }
    }
    floyd(n, timeTo);

    printf("Case #%d:", tc);
    for(int i = 0; i < q; i++) {
      printf(" %.9Lf", timeTo[u[i] - 1][v[i] - 1]);
    }
    printf("\n");
  }
  return 0;
}	}
			}
		}
		cout << "Case " << a0 << ":";
		for(int a1 = 0; a1 < q; ++a1){
			int src, dest;
			cin >> src >> dest;
			cout << fixed << setprecision(11) << " " << time[src][dest];
		}
		cout << "\n";
	}
	return 0;
}

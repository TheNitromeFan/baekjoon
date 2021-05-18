#include <iostream>
#define MAX 201
#define INFTY 1000000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a[MAX][MAX], connect[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == j){
				a[i][j] = 0;
				connect[i][j] = i;
			}else{
				a[i][j] = INFTY;
				connect[i][j] = INFTY;
			}
		}
	}
	for(int a0 = 0; a0 < m; ++a0){
		int u, v, w;
		cin >> u >> v >> w;
		if(a[u][v] > w){
			a[u][v] = w;
			a[v][u] = w;
			connect[u][v] = v;
			connect[v][u] = u;
		}
	}
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(a[i][j] > a[i][k] + a[k][j]){
					a[i][j] = a[i][k] + a[k][j];
					connect[i][j] = connect[i][k];
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == j){
				cout << '-' << ' ';
			}else{
				cout << connect[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
